/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_notice.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:52:32 by daraz             #+#    #+#             */
/*   Updated: 2024/09/28 10:24:53 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Server.hpp"

/*
    Command: NOTICE
    Parameters: <channel/user> <message>

    The NOTICE command allows a client to send a message to another user or a channel,
	but unlike the PRIVMSG command, no automated responses are triggered.
*/
void Server::ft_notice(Request request)
{
	User* user = request.get_user();
	if (user->is_registered() == false || request.get_params().size() < 2)
		return;
	std::string duplicate, message;
	std::set<std::string> targets = split_comma(request.get_params()[0], duplicate);
	for (size_t i = 1; i < request.get_params().size(); ++i)
		message += request.get_params()[i] + (i < request.get_params().size() - 1 ? " " : "");
	for (std::set<std::string>::const_iterator it = targets.begin(); it != targets.end(); ++it)
	{
		usermap::iterator recipient = get_user_by_nick(*it);
		channelmap::iterator channel = _channels.find(*it);
		if (channel != _channels.end() && channel->second.check_is_member(user) == false)
			continue;
		if (recipient != _user_map.end())
		{
			std::string notice_msg = user->get_prefix() + " NOTICE " + *it + " :" + message;
			send_message(notice_msg, recipient->first);
		}
		else if (channel != _channels.end())
		{
			const std::list<User*>& members = channel->second.getMembers();
			for (std::list<User*>::const_iterator user_it = members.begin(); user_it != members.end(); ++user_it)
			{
				if (*user_it != user)
				{
					std::string notice_msg = user->get_prefix() + " NOTICE " + *it + " :" + message;
					send_message(notice_msg, (*user_it)->get_fd());
				}
			}
		}
	}
}
