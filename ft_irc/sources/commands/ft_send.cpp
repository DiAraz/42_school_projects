/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:18:09 by daraz             #+#    #+#             */
/*   Updated: 2024/10/02 17:25:01 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/Server.hpp"

/*
	Command: SEND
	Parameters: <filename> <target>
	
	SEND command is used for a file transferring via server storage.
*/
void Server::ft_send(Request request)
{
    if (request.get_params().size() < 2)
    {
        send_message(request, RES_ERR_NEEDMOREPARAMS);
        return;
    }

    std::string filename = request.get_params()[0];
    std::string target_nick = request.get_params()[1];
    User* sender = request.get_user();

    Server::usermap::iterator recipient = get_user_by_nick(target_nick);
    if (recipient == _user_map.end())
    {
        send_message(request, RES_ERR_NOSUCHNICK);
        return;
    }

    if (sender == &recipient->second)
    {
        send_message(request, RES_ERR_USERISRECEIVER);
        return;
    }

    std::ifstream file(filename.c_str(), std::ios::binary);
    if (!file.is_open())
    {
        send_message(request, RES_ERR_NOFILEPROVIDED);
        return;
    }

    std::string file_content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    _file_storage[target_nick] = file_content;

    std::string notification = std::string(SERVER_NAME) + " 1103 " + sender->get_nickname() + ": has sent you a file: " + filename;
    send_message(notification, recipient->second.get_fd());

    std::string confirmation_message = std::string(SERVER_NAME) + " 1104 " + sender->get_nickname() + ": File '" + filename + "' successfully sent to " + target_nick;
    send_message(confirmation_message, sender->get_fd());
}
