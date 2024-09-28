/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oper.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:39:35 by daraz             #+#    #+#             */
/*   Updated: 2024/09/28 10:33:32 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/Server.hpp"

/*
	Command: OPER
	Parameters: <user> <password>

	The OPER command in IRC is used by a client to request operator privileges on the server.
	It requires two parameters: a username and a password. If the provided credentials match the server's operator credentials,
	the client is granted operator status and can perform privileged operations like managing channels and users. 
*/
void Server::ft_oper(Request request)
{
	User *user = request.get_user();

	if (!user->is_registered())
	{
		send_message(SERVER_NAME " 462 " + user->get_nickname() + " :Unauthorized command (not yet registered)", user->get_fd());
		return;
	}

	bool is_operator_in_any_channel = false;
	for (channelmap::iterator ch_it = _channels.begin(); ch_it != _channels.end(); ++ch_it)
	{
		if (ch_it->second.check_is_operator(user))
		{
			is_operator_in_any_channel = true;
			break;
		}
	}

	if (is_operator_in_any_channel)
	{
		send_message(SERVER_NAME " 481 " + user->get_nickname() + " :Permission Denied- You're already an operator", user->get_fd());
		return;
	}

	if (request.get_params().size() < 2)
	{
		send_message(SERVER_NAME " 461 " + user->get_nickname() + " OPER :Not enough parameters", user->get_fd());
		return;
	}

	std::string username = request.get_params()[0];
	std::string password = request.get_params()[1];

	if (username == OPER_LOG && password == OPER_PASS)
	{
		for (channelmap::iterator ch_it = _channels.begin(); ch_it != _channels.end(); ++ch_it)
		{
			if (ch_it->second.check_is_member(user))
			{
				ch_it->second.add_operator(user);
			}
		}
		send_message(SERVER_NAME " 381 " + user->get_nickname() + " :You are now an IRC operator", user->get_fd());
	}
	else
	{
		send_message(SERVER_NAME " 464 " + user->get_nickname() + " :Invalid username or password", user->get_fd());
	}
}
