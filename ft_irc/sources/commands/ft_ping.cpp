/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:47:31 by daraz             #+#    #+#             */
/*   Updated: 2024/09/28 10:33:32 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/Server.hpp"

/*
	Command: PING
	Parameters: <token>
	
	In IRC, the PING command is used to check if a client or server is still active and responsive.
	When a server sends a PING to a client, the client must reply with a PONG to confirm that it is still connected.
*/
void Server::ft_ping(Request request)
{
	std::string response(SERVER_NAME);
	if (request.get_params().size() == 0)
		response.append(" 461 " + request.get_user()->get_nickname() + " :Not enough parameters.");
	else if (request.get_params()[0].empty())
		response.append(" 409 " + request.get_user()->get_nickname() + " :No origin specified");
	else
		response.append(" PONG " + request.get_params()[0]);
	send_message(response, request.get_user()->get_fd());
}
