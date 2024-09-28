/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cap.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:11:08 by daraz             #+#    #+#             */
/*   Updated: 2024/09/28 10:32:33 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/Server.hpp"

/*
	Command: CAP
	Parameters: LS / REQ
	
	When a client connects to the IRC server, it may send CAP LS to list the server’s supported capabilities.
*/
void Server::ft_cap(Request request)
{
	std::string response;
	
	if (request.get_params()[0] == "LS" || request.get_params()[0] == "ls")
	{
		response = (SERVER_NAME " CAP * LS :End of CAP LS negotiation");
		send_message(response, request.get_user()->get_fd());
	}
}
