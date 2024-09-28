/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:25:10 by daraz             #+#    #+#             */
/*   Updated: 2024/09/28 10:33:32 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/Server.hpp"

/*
	Command: QUIT
	Parameters: [<message>]

	The QUIT command in IRC is used when a client wants to disconnect from the server.
	A client session is terminated with a quit message. The server
	acknowledges this by sending an ERROR message to the client.
*/
void Server::ft_quit(Request request)
{
	User* user = request.get_user();
	std::string quit_message = (request.get_params().empty()) ? "" : (":" + request.get_params()[0]);

	std::string quit_notice = user->get_prefix() + " QUIT " + quit_message;
	for (channelmap::iterator ch_it = _channels.begin(); ch_it != _channels.end(); ++ch_it)
	{
		if (ch_it->second.check_is_member(user))
		{
			const std::list<User*>& members = ch_it->second.getMembers(0);
			for (std::list<User*>::const_iterator member_it = members.begin(); member_it != members.end(); ++member_it)
			{
				if ((*member_it)->get_fd() != user->get_fd())
				{
					send_message(quit_notice, (*member_it)->get_fd());
				}
			}
		}
	}
	remove_client(user, quit_message);
}
