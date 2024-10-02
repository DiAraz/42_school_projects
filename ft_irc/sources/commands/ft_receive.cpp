/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_receive.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:18:05 by daraz             #+#    #+#             */
/*   Updated: 2024/10/02 17:29:38 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/Server.hpp"

/*
	Command: RECEIVE
	Parameters: <filename>
	
	RECEIVE command is used to get the sent file from the server storage.
*/
void Server::ft_receive(Request request)
{
    if (request.get_params().size() < 1)
    {
        send_message(request, RES_ERR_NEEDMOREPARAMS);
        return;
    }

    std::string filename = request.get_params()[0];
    User* recipient = request.get_user();
    std::string recipient_nick = recipient->get_nickname();

    if (_file_storage.find(recipient_nick) == _file_storage.end())
    {
        std::string error_message = std::string(SERVER_NAME) + " 1105 " + recipient->get_nickname() + " : No file available for you.";
        send_message(error_message, recipient->get_fd());
        return;
    }

    std::string file_content = _file_storage[recipient_nick];

    std::string notification = std::string(SERVER_NAME) + " 1107 " + recipient->get_nickname() + " : Receiving file '" + filename + "'. Content:\n" + file_content;
    send_message(notification, recipient->get_fd());

    _file_storage.erase(recipient_nick);

    std::string confirmation_message = std::string(SERVER_NAME) + " 1108 " + recipient->get_nickname() + " : File '" + filename + "' successfully received.";
    send_message(confirmation_message, recipient->get_fd());
}
