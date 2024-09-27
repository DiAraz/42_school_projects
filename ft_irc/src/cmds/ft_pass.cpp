/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pass.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:48:34 by daraz             #+#    #+#             */
/*   Updated: 2024/09/25 15:00:22 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

/*
	Command: PASS
	Parameters: <password>
	
	In IRC, the PASS command is used to set a connection password
	that a client must provide before registering their nickname and user information. 
*/
void Server::ft_pass(Request request)
{
	User* user = request.get_user();
	std::string response;

	if (user->is_registered())
	{
		response = SERVER_NAME " 462 " + user->get_nickname() + " :Unauthorized command (already registered)";
	}
	else if (request.get_params().empty() || request.get_params().size() != 1)
	{
		response = SERVER_NAME " 461 " + user->get_nickname() + " PASS :Not the right amount of parameters";
	}
	else if (request.get_params()[0] != _password)
	{
		response = SERVER_NAME " 464 " + user->get_nickname() + " :Password incorrect";
		user->set_pass_provided(false);
	}
	else
	{
		user->set_pass_provided(true);
		return;
	}
	send_message(response, user->get_fd());
}
