/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kick.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:48:57 by daraz             #+#    #+#             */
/*   Updated: 2024/09/28 10:32:59 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/Server.hpp"

std::vector<std::string> split(const std::string& str, char delimiter)
{
	std::vector<std::string> tokens;
	std::stringstream ss(str);
	std::string token;

	while (std::getline(ss, token, delimiter))
		tokens.push_back(token);
	return tokens;
}

/*
	Command: KICK
	Parameters: <channel1,channel2> <nick1,nick2> [<reason>]

	The KICK command allows a channel operator to forcibly remove users from a channel.
*/
void Server::ft_kick(Request request)
{
    std::vector<std::string> params = request.get_params();
    User* user = request.get_user();
    
    if (!user->is_registered()) 
    {
        send_message(SERVER_NAME " 462 " + user->get_nickname() + " :Unauthorized command (not yet registered)", user->get_fd());
        return;
    }
    if (params.size() < 2)
    {
        send_message(SERVER_NAME " 461 " + user->get_nickname() + " KICK :Not enough parameters", user->get_fd());
        return;
    }

    std::vector<std::string> channels = split(params[0], ',');
    std::vector<std::string> users_to_kick = split(params[1], ',');
    std::string comment = (params.size() > 2) ? params[2] : user->get_nickname();
    for (std::vector<std::string>::size_type i = 0; i < channels.size(); ++i)
    {
        Channel* channel = find_channel(channels[i]);
        if (!channel)
        {
            send_message(SERVER_NAME " 403 " + channels[i] + " :No such channel", user->get_fd());
            continue;
        }

        if (!channel->check_is_operator(user))
        {
            send_message(SERVER_NAME " 482 " + channels[i] + " :You're not a channel operator", user->get_fd());
            continue;
        }
        for (std::vector<std::string>::size_type j = 0; j < users_to_kick.size(); ++j)
        {
            usermap::iterator target_user_it = get_user_by_nick(users_to_kick[j]);
            if (target_user_it == _user_map.end())
            {
                request.set_info(users_to_kick[j]);
                send_message(request, RES_ERR_NOSUCHNICK);
                continue;
            }

            User* target_user = &target_user_it->second;
            if (user == target_user)
            {
                send_message(SERVER_NAME " 482 " + channels[i] + " :You cannot kick yourself", user->get_fd());
                continue;
            }
            if (!channel->getMember(target_user->get_nickname()))
            {
                request.set_info(target_user->get_nickname());
                request.set_channel_name(channel->getName());
                send_message(request, RES_ERR_USERNOTINCHANNEL);
                continue;
            }
            std::string kick_message = "KICK " + channels[i] + " " + target_user->get_nickname() + " :" + comment;
            channel->remove(target_user);
            send_message(kick_message, target_user->get_fd());

            for (std::list<User*>::const_iterator it = channel->getMembers().begin(); it != channel->getMembers().end(); ++it)
            {
                send_message(kick_message, (*it)->get_fd());
            }
            if (channel->getMembers().empty())
            {
                _channels.erase(channel->getName());
            }
            if (channels.size() > 1 && users_to_kick.size() == 1)
                break;
        }
    }
}
