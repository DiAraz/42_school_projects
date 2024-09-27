/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_globops.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:26:03 by daraz             #+#    #+#             */
/*   Updated: 2024/09/25 13:54:24 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Server.hpp"

/*
    Command: GLOBOPS
    Parameters: <message>

    Only IRC operators can use this command.
    When an IRC operator uses this command, it broadcasts the specified <message> to all other IRC operators across the server.
*/
void Server::ft_globops(Request request)
{
    std::string response;
    User* user = request.get_user();

    if (!user->is_registered())
    {
        response = SERVER_NAME " 462 " + user->get_nickname() + " :Unauthorized command (not yet registered)";
    }
    else
    {
        bool is_channel_operator = false;
        for (std::map<std::string, Channel>::iterator it = _channels.begin(); it != _channels.end(); ++it)
        {
            if (it->second.check_is_operator(user))
            {
                is_channel_operator = true;
                break;
            }
        }

        if (!is_channel_operator)
        {
            response = SERVER_NAME " 481 " + user->get_nickname() + " :Permission Denied- You're not an IRC operator in any channel";
        }
    }

    if (response.empty() && request.get_params().size() == 0)
    {
        response = SERVER_NAME " 461 " + user->get_nickname() + " :Not enough parameters";
    }
    if (!response.empty())
    {
        send_message(response, user->get_fd());
        return;
    }
    std::string params;
    for (size_t i = 0; i < request.get_params().size(); i++)
    {
        params += request.get_params()[i];
        if (i != request.get_params().size() - 1)
            params += " ";
    }
    for (std::map<int, User>::iterator it = _user_map.begin(); it != _user_map.end(); ++it)
    {
        if (it->second.get_fd() != user->get_fd())
        {
            bool recipient_is_operator = false;
            for (std::map<std::string, Channel>::iterator ch_it = _channels.begin(); ch_it != _channels.end(); ++ch_it)
            {
                if (ch_it->second.check_is_operator(&it->second))
                {
                    recipient_is_operator = true;
                    break;
                }
            }
            if (recipient_is_operator)
            {
                send_message(":" + user->get_nickname() + "!" + user->get_nickname() + "@" + user->get_hostmask() + " GLOBOPS :" + params, it->second.get_fd());
            }
        }
    }
}

