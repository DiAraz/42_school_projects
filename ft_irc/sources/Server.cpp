/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:16:34 by daraz             #+#    #+#             */
/*   Updated: 2024/10/02 16:49:38 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Server.hpp"

Server::Server(char **argv)
{
    char *end_ptr = NULL;
    long port = strtol(argv[1], &end_ptr, 0);
    if (*end_ptr != '\0' || port <= 0 || port > 65535) //65535 because port numbers are stored in a 16-bit unsigned integer field in network protocols like TCP and UDP
	{
        throw InvalidPort();
	}
    _port = static_cast<int>(port);

    std::string password_input = argv[2];
	if (password_input.empty())
	{
		throw IncorrectPass();
	}
	_password = password_input;

    time_t current_time = time(NULL);
    _creation_time = ctime(&current_time);
    _creation_time.erase(_creation_time.size() - 1);
}

int	Server::get_port(){return _port;}

std::string	Server::get_password(){return _password;}

const Server::channelmap &Server::getChannels(void) 
	const {return (_channels);}

void Server::socket_construction()
{
    struct sockaddr_in server_addr;

    // Create socket with IPv4 and TCP
    _listening_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (_listening_socket < 0)
        throw SocketSetupFail();

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET; // Internet address family
    server_addr.sin_port = htons(_port); // Convert port number to network byte order
    server_addr.sin_addr.s_addr = INADDR_ANY; // Bind to any available network interface

    // Allow the socket to reuse the address (SO_REUSEADDR)
    int reuse_option = 1;
    if (setsockopt(_listening_socket, SOL_SOCKET, SO_REUSEADDR, &reuse_option, sizeof(reuse_option)) < 0)
        throw SocketOptionFail();

    // Set the socket to non-blocking mode
    if (fcntl(_listening_socket, F_SETFL, O_NONBLOCK) == -1)
        throw SocketOptionFail();

    // Bind the socket to the address and port
    if (bind(_listening_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
        throw SocketBindFail();

    // Start listening for incoming connections with a maximum queue length
    if (listen(_listening_socket, SOMAXCONN) < 0)
        throw SocketListenFail();

    bzero(_user_map_poll, sizeof(_user_map_poll));
    _user_map_poll[0].fd = _listening_socket;
    _user_map_poll[0].events = POLLIN | POLLHUP | POLLOUT;
    _fd_count = 1;
}

void Server::accept_new_client()
{
    int client_socket_fd;
    sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);

    client_socket_fd = accept(_listening_socket, (sockaddr *)&client_address, &client_address_len);
    if (client_socket_fd == -1)
    {
        std::cerr << "Failed to accept new client" << std::endl;
        throw SocketAcceptFail();
    }

    char client_ip[INET_ADDRSTRLEN];
    if (!inet_ntop(AF_INET, &client_address.sin_addr, client_ip, INET_ADDRSTRLEN))
    {
        std::cerr << "Failed to convert client IP" << std::endl;
        throw SocketAcceptFail();
    }

    User new_user(client_socket_fd, client_ip);
    _user_map[client_socket_fd] = new_user;

    add_client_to_poll(client_socket_fd);
    std::cout << "New client connected with fd: " << client_socket_fd << " and IP: " << client_ip << std::endl;
}

void Server::remove_client(User* user, std::string reason)
{
	std::vector<std::string> channels_to_cleanup;
	int user_socket_fd = user->get_fd();

	for (channelmap::iterator channel_it = _channels.begin(); channel_it != _channels.end(); ++channel_it)
	{
		if (channel_it->second.check_is_member(user))
		{
			if (channel_it->second.remove(user))
				channels_to_cleanup.push_back(channel_it->second.getName());

			const std::list<User*>& members_list = channel_it->second.getMembers(0);
			for (std::list<User*>::const_iterator member_it = members_list.begin(); member_it != members_list.end(); ++member_it)
			{
				send_message(user->get_prefix() + " QUIT : " + reason, (*member_it)->get_fd());
			}
		}
	}
	for (std::vector<std::string>::const_iterator cleanup_it = channels_to_cleanup.begin(); cleanup_it != channels_to_cleanup.end(); ++cleanup_it)
	{
		_channels.erase(*cleanup_it);
	}
	for (unsigned int i = 0; i < _fd_count; ++i)
	{
		if (_user_map_poll[i].fd == user_socket_fd)
		{
			remove_client_from_poll(i);
			break;
		}
	}
	_user_map.erase(user_socket_fd);
}

void Server::server_loop() 
{
    socket_construction();
    bool server_running = true;
    while (server_running) 
    {
        int poll_status = poll(_user_map_poll, _fd_count, -1);//-1 means wait indefinitely
        if (poll_status == -1)
        {
            throw PollFailed();
        }

        unsigned int clients_to_check = _fd_count;

        for (unsigned int index = 0; index < clients_to_check; ++index) 
        {
            try 
            {
                if (_user_map_poll[index].revents & POLLIN) 
                {
                    if (_user_map_poll[index].fd == _listening_socket) 
                    {
                        accept_new_client();
                    } 
                    else 
                    {
                        handle_client_request(index);
                    }
                }
                else if ((_user_map_poll[index].revents & POLLHUP) || (_user_map_poll[index].revents & POLLOUT)) 
                {
                    std::map<int, User>::iterator it = _user_map.find(_user_map_poll[index].fd);
                    if (it != _user_map.end()) 
                    {
                        remove_client(&(it->second), "disconnected");
                    }
                }
            } 
            catch (const std::exception &e) 
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }

    close(_listening_socket);
}

void Server::add_client_to_poll(int user_fd)
{
	if (_fd_count >= SOMAXCONN)
		throw PollOverflow();
	
	_user_map_poll[_fd_count].fd = user_fd;
	_user_map_poll[_fd_count].events = POLLIN;

	++_fd_count;
}

void Server::remove_client_from_poll(int index)
{
	close(_user_map_poll[index].fd);
	_user_map_poll[index].fd = _user_map_poll[_fd_count-1].fd;
	_user_map_poll[index].events = POLLIN;
	_user_map_poll[_fd_count - 1].fd = -1;
	
	--_fd_count;
}

void Server::handle_client_request(int poll_index)
{
	int client_fd = _user_map_poll[poll_index].fd;
	char buffer[MAXLINE] = {0};
	int bytes_received = recv(client_fd, buffer, sizeof(buffer), 0);

	if (bytes_received > 0)
	{
		process_command(buffer, client_fd);
	}
	else
	{
		if (bytes_received == 0)
		{
			std::cout << "Client (fd) " << client_fd << " disconnected" << std::endl;
		}
		else
		{
			throw ReceiveMessageFail();
		}
		std::map<int, User>::iterator user_itr = _user_map.find(client_fd);
		if (user_itr != _user_map.end())
		{
			remove_client(&(user_itr->second), "disconnected");
		}
	}
}

void Server::process_command(char* input, int fd)
{
	User* current_user = &_user_map[fd];
	current_user->input_append(input);
	while (true)
	{

		size_t position = current_user->buff.find(RESPONSE_END);

		if (position == std::string::npos || position == 512)
			break;
		std::string command = current_user->buff.substr(0, position);
		current_user->buff.erase(0, position + 2);
		Request cmd_request(command, current_user);
		cmd_request.print_parsed_request();
		command_exec(cmd_request);
		if (_user_map.find(fd) == _user_map.end())
			return;
	}
}

void Server::command_exec(Request request)
{
	std::string cmd = request.get_cmd();
	std::map<std::string, void (Server::*)(Request)> command_map;

	command_map["CAP"] = &Server::ft_cap;
	command_map["PING"] = &Server::ft_ping;
	command_map["PASS"] = &Server::ft_pass;
	command_map["NICK"] = &Server::ft_nick;
	command_map["USER"] = &Server::ft_user;
	command_map["PRIVMSG"] = &Server::ft_privmsg;
	command_map["QUIT"] = &Server::ft_quit;
	command_map["JOIN"] = &Server::ft_join;
	command_map["NAMES"] = &Server::ft_join;
	command_map["GLOBOPS"] = &Server::ft_globops;
	command_map["LIST"] = &Server::ft_list;
	command_map["TOPIC"] = &Server::ft_topic;
	command_map["OPER"] = &Server::ft_oper;
	command_map["PART"] = &Server::ft_part;
	command_map["WHO"] = &Server::ft_who;
	command_map["MODE"] = &Server::ft_mode;
	command_map["KILL"] = &Server::ft_kill;
	command_map["KICK"] = &Server::ft_kick;
	command_map["NOTICE"] = &Server::ft_notice;
	command_map["INVITE"] = &Server::ft_invite;
	command_map["TIME"] = &Server::ft_time;
	command_map["JOKE"] = &Server::ft_joke;
	command_map["SEND"] = &Server::ft_send;
	command_map["RECEIVE"] = &Server::ft_receive;

	std::map<std::string, void (Server::*)(Request)>::iterator it = command_map.find(cmd);
	if (it != command_map.end()) {
		(this->*it->second)(request);
	} else {
		send_message(SERVER_NAME " 421 " + request.get_user()->get_nickname() + " " + cmd + " :Unknown command", request.get_user()->get_fd());
	}
}

std::map<int, User>::iterator Server::get_user_by_nick(std::string nickname)
{
	std::map<int, User>::iterator user_it = _user_map.begin();
	std::map<int, User>::iterator user_end = _user_map.end();

	while (user_it != user_end)
	{
		if (user_it->second.get_nickname() == nickname)
			return user_it;

		++user_it;
	}
	return user_end;
}

void Server::send_message(std::string message, int fd)
{
	std::cout << "SERVER RESPONSE < " << message << " >" << std::endl;
	send(fd, message.append(RESPONSE_END).c_str(), message.size(), 0);
}

Channel* Server::find_channel(std::string channel_name)
{
	std::map<std::string, Channel>::iterator it = _channels.find(channel_name);
	if (it != _channels.end())
		return &(it->second);
	return NULL;
}

bool Channel::handle_mode_options(char mode, char sign, std::string param, const Server & server, Request request)
{
	User	*user;

	if (mode == 'i' || mode == 't')
		return (true);
	else if (mode == 'o')
	{
		if (param.empty())
		{
			server.send_message(request, RES_ERR_NEEDMOREPARAMS);
			return (false);
		}
		user = getMember (param);
		if (request.get_user() == user && sign == '-')
			return (false);
		request.set_info (param); 
		if (user == NULL)
		{
			server.send_message (request, RES_ERR_USERNOTINCHANNEL);
			return (false);
		}
		if (sign == '+' && check_is_operator (user))
		{
			server.send_message (request, RES_ERR_ALREADYANOPERATOR);
			return (false);	
		}
		else if (sign == '+')
			add_operator (user);
		else if (!check_is_operator (user))
		{
			server.send_message (request, RES_ERR_NOTANOPERATOR);
			return (false);
		}
		else
			operator_remove (user);
		return (true);
	}
	else if (mode == 'k')
	{
		if (sign == '-')
		{
			setPassword("*");
			return true;
		}
		else
		{
			setPassword(param);
			return true;
		}
	}
	else if (mode == 'l')
	{
		if (sign == '-')
		{
			setLimit(-1);
			return true;
		}
		else
		{
			int update_limit = strtol(param.c_str(), NULL, 10);
			if (update_limit >= static_cast<int>(_members.size()))
			{
				_limit = update_limit;
				std::cout << "set limit to " << _limit << std::endl;
				return true;
			}
		}
	}
	return false;
}

void Channel::operator_remove(User *op)
{
    _ops.remove(op);
    if (_ops.empty() && !_members.empty())
    {
        User *new_op = *_members.begin();
        add_operator(new_op);

        std::string broadcast_message = ":" + std::string(SERVER_NAME)
            + " MODE " + _name + " +o " + new_op->get_nickname();
        
        Server::broadcast(broadcast_message, NULL, *this);
    }
}