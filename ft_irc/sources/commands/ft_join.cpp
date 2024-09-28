/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:45:10 by daraz             #+#    #+#             */
/*   Updated: 2024/09/28 12:11:28 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/Server.hpp"

void Server::get_names_list(Request &request, Channel &channel)
{
	std::string info;
	std::list<User *>::const_iterator userIt;

	userIt = channel.getMembers().begin();
	while (userIt != channel.getMembers().end())
	{
		if (userIt != channel.getMembers().begin())
			info += ' ';
		info += (*userIt)->get_nickname();
		userIt++;
	}
	send_message(SERVER_NAME " 353 " + request.get_user()->get_nickname() + " = " + channel.getName() + " :" + info, request.get_user()->get_fd());
	send_message(SERVER_NAME " 366 " + request.get_user()->get_nickname() + " " + channel.getName() + " :End of NAMES list", request.get_user()->get_fd());
}	

void Server::broadcast (std::string message, User* user, Channel& channel)
{
	std::list<User*>::const_iterator userIt;
	
	for (userIt = channel.getMembers().begin(); userIt != channel.getMembers().end(); ++userIt)
		if (user == NULL || (*userIt) != user)
			send_message(message, (*userIt)->get_fd());
}

/*
	Command: JOIN
	Parameters: <channel,channels> [<password>]

	JOIN command allows a user to join a channel. If the channel doesn't exist, it gets created.
*/
/*
	Command: NAMES
	Parameters: <channel,channels>

	NAMES command command returns a list of all users in a specific channel, which can be requested without joining. 
*/
void Server::ft_join( Request request )
{
    if (request.get_params().empty()) 
    {
        send_message(request, RES_ERR_NEEDMOREPARAMS);
        return;
    }

    if (!request.get_user()->is_registered() && request.get_cmd() == "JOIN") 
    {
        send_message(request, RES_ERR_NOTREGISTERED);
        return;
    }

    std::string channelNames = request.get_params()[0];
    std::string passwords = (request.get_params().size() > 1) ? request.get_params()[1] : "*";

    size_t pos;
    size_t pos2;
    while (!channelNames.empty()) 
    {
        pos = channelNames.find(",");
        std::string channelName = channelNames.substr(0, pos);
        channelNames = (pos < channelNames.length()) ? channelNames.substr(pos + 1) : "";
        pos2 = passwords.find(",");
        std::string password = passwords.substr(0, pos2);
        passwords = (pos2 < passwords.length()) ? passwords.substr(pos2 + 1) : "*";

        request.set_channel_name(channelName);

        if (!Channel::check_correct_channel_name(channelName)) 
        {
            send_message(request, RES_ERR_BADCHANNAME);
            continue;
        }

        if (!request.get_user()->is_registered()) 
        {
            send_message(request, RES_ERR_NOTREGISTERED);
            continue;
        }

        channelmap::iterator it = _channels.find(channelName);
        if (request.get_cmd() == "JOIN") 
        {
            if (it == _channels.end()) 
            {
                _channels.insert(std::make_pair(channelName, Channel(channelName, password)));
                it = _channels.find(channelName);
            }

            if (it->second.getPassword() != "*" && (password == "*" || password != it->second.getPassword())) 
            {
                std::cout << "Failed to join channel: [" + channelName + "], provided password: [" 
                          + password + "], channel password: [" + it->second.getPassword() + "]" << std::endl;
                send_message(request, (password == "*") ? RES_ERR_BANNEDFROMCHAN : RES_ERR_BADCHANNELKEY);
                continue;
            }

            if (it->second.check_is_member(request.get_user())) 
            {
                send_message(request, RES_ERR_CHANNELALREADYJOINED);
                continue;
            }

            if (it->second.check_has_mode('l') && it->second.getLimit() != -1 && 
                static_cast<int>(it->second.getMembers().size()) >= it->second.getLimit()) 
            {
                send_message(request, RES_ERR_CHANNELISFULL);
                continue;
            }

            it->second.add_member(request.get_user());
            send_message(request, RES_CHANNELJOINED);
            broadcast(":" + request.get_user()->get_nickname() + "!" + request.get_user()->get_nickname() + "@" SERVER_NAME 
                      " JOIN " + it->second.getName(), request.get_user(), it->second);

            request.get_user()->getChannels(0).insert(std::make_pair(it->first, &it->second));
            get_names_list(request, it->second);
            std::list<User*>::const_iterator opIt;
            for (opIt = it->second.getOps().begin(); opIt != it->second.getOps().end(); ++opIt) 
            {
                send_message(":" + std::string(SERVER_NAME) + " MODE " + it->second.getName() + " +o " + (*opIt)->get_nickname(), 
                             request.get_user()->get_fd());
            }

            if (it->second.getTopic() != "*") 
            {
                std::ostringstream stream;
                stream << static_cast<int>(RES_RPL_TOPIC);
                send_message(":" + std::string(SERVER_NAME) + " " + stream.str() + " " + request.get_user()->get_nickname() 
                             + " " + it->second.getName() + " :" + it->second.getTopic(), request.get_user()->get_fd());
            }
        }
        else if (request.get_cmd() == "NAMES") 
        {
            if (it == _channels.end()) 
            {
                send_message(request, RES_ERR_NOSUCHCHANNEL);
                continue;
            }

            std::string userList;
            std::list<User*>::const_iterator userIt;
            for (userIt = it->second.getMembers().begin(); userIt != it->second.getMembers().end(); ++userIt) 
            {
                if (!userList.empty()) 
                    userList += ' ';
                userList += (*userIt)->get_nickname();
            }
            send_message(SERVER_NAME " 353 " + request.get_user()->get_nickname() + " = " + channelName + " :" + userList, 
                         request.get_user()->get_fd());
            send_message(SERVER_NAME " 366 " + channelName + " :End of NAMES list", request.get_user()->get_fd());
        }
    }
}