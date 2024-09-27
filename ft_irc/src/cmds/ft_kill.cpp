/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:42:11 by daraz             #+#    #+#             */
/*   Updated: 2024/09/25 13:53:47 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Server.hpp"

/*
    Command: KILL
    Parameters: <nickname> <reason> 

    The KILL command in IRC is used by operators to forcibly disconnect a user from the server. 
*/
void Server::ft_kill(Request request)
{
    std::string response;
    std::vector<std::string> params = request.get_params();
    User* user = request.get_user();
    if (!user->is_registered()) 
    {
        send_message(SERVER_NAME " 462 " + user->get_nickname() + " :Unauthorized command (not yet registered)", user->get_fd());
        return;
    }
    if (params.size() < 2)
    {
        response = SERVER_NAME " 461 " + user->get_nickname() + " :Not enough parameters (include nick and reason)";
        send_message(response, user->get_fd());
        return;
    }

    std::string user_to_kill = params[0];
    std::string reason = params[1];
    usermap::iterator dead_user_it = get_user_by_nick(user_to_kill);
    if (dead_user_it == _user_map.end()) 
    {
        response = SERVER_NAME " 401 " + user_to_kill + " :No such nick/channel";
        send_message(response, user->get_fd());
        return;
    }
    User* dead_user = &dead_user_it->second;
    bool is_operator_in_any_channel = false;
    for (channelmap::iterator ch_it = _channels.begin(); ch_it != _channels.end(); ++ch_it)
    {
        if (ch_it->second.check_is_operator(user))
        {
            is_operator_in_any_channel = true;
            break;
        }
    }
    if (!is_operator_in_any_channel) 
    {
        response = SERVER_NAME " 481 " + user->get_nickname() + " :Permission Denied - You're not a channel operator";
        send_message(response, user->get_fd());
        return;
    }

    std::string message = user_to_kill + " killed by " + user->get_nickname() + " (" + reason + ")";
    remove_client(dead_user, message);
}
