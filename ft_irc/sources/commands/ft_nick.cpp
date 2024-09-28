/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nick.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:42:52 by daraz             #+#    #+#             */
/*   Updated: 2024/09/28 10:33:32 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/Server.hpp"

bool check_valid_chars(std::string nickname)
{
    std::string forbidden = "!@#$%^&*()+={}[];,:\"\t'<>.";
    
    for (unsigned int i = 0; i < forbidden.size(); ++i)
    {
        if (nickname.find(forbidden[i]) != std::string::npos)
        {
            std::cout << "nickname is |" << nickname << std::endl;
            std::cout << "forbidden char is " << forbidden[i] << std::endl;
            return true;
        }
    }
    return false;
}

void	Server::print_login(User *user)
{
	std::string	nickname = user->get_nickname();
	int			fd = user->get_fd();

	if (user->is_pass_provided() && nickname != "*" && user->get_name() != "*" && user->is_registered() == false)
	{
		send_message(SERVER_NAME " 001 " + nickname + " :Welcome to the Internet Relay Network " + nickname + "!" + user->get_name() + "@" + user->get_hostmask(), fd);
		send_message(SERVER_NAME " 002 " + nickname + " :Your host is " SERVER_NAME " running version " VERSION, fd);
		send_message(SERVER_NAME " 003 " + nickname + " :This server was created " + _creation_time, fd);
		user->set_registered(true);
	}
}

/*
	Command: NICK
	Parameters: <nickname>
	The NICK command in IRC is used to assign or change the nickname of a user.
*/
void Server::ft_nick(Request request)
{
	User *user = request.get_user();
	std::string new_nick = (request.get_params().size() == 1) ? request.get_params()[0] : "";
	std::string response;

	if (!user->is_pass_provided())
	{
		response = SERVER_NAME " 464 " + user->get_nickname() + " :Please provide the server password with PASS first";
	}
	else if (new_nick.empty())
	{
		response = SERVER_NAME " 431 " + user->get_nickname() + " :No nickname provided";
	}
	else if (check_valid_chars(new_nick))
	{
		response = SERVER_NAME " 432 " + user->get_nickname() + " " + new_nick + " :Invalid character in nickname";
	}
	else if (get_user_by_nick(new_nick) != _user_map.end())
	{
		response = SERVER_NAME " 433 " + user->get_nickname() + " " + new_nick + " :Nickname already in use";
	}
	else
	{
		response = user->get_prefix() + " NICK " + new_nick;
		user->set_nickname(new_nick);
		std::map<std::string, Channel *>::iterator it;
		for (it = user->getChannels(0).begin(); it != user->getChannels(0).end(); ++it)
		{
			broadcast(response, user, *(it->second));
		}
	}
	if (!response.empty())
	{
		send_message(response, user->get_fd());
	}
	print_login(user);
}
