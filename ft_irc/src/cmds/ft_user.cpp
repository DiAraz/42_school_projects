/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_user.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:52:47 by daraz             #+#    #+#             */
/*   Updated: 2024/09/27 10:18:47 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Server.hpp"

/*
	Command: USER
	Parameters: <user> <mode> <unused> <realname>

	The USER command in IRC is used during the initial connection
	to specify a new user's details, including their username and real name.
*/
void Server::ft_user(Request request)
{
	User* user = request.get_user();
	std::string response;

	if (!user->is_pass_provided()) 
	{
		response = SERVER_NAME " 462 " + user->get_nickname() + " :Please provide the server password with PASS first";
	}
	else if (user->is_registered()) 
	{
		response = SERVER_NAME " 462 " + user->get_nickname() + " :Unauthorized command (already registered)";
	}
	else if (request.get_params().size() != 4) 
	{
		response = SERVER_NAME " 461 " + user->get_nickname() + " USER :Not the right parameters";
	}
	else 
	{
		user->set_name(request.get_params()[0]);
		user->set_fullname(request.get_params()[3]);
		print_login(user);
	}
	if (!response.empty()) 
	{
		send_message(response, user->get_fd());
	}
}