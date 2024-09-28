/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_privmsg.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 09:46:56 by daraz             #+#    #+#             */
/*   Updated: 2024/09/28 10:33:32 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/Server.hpp"

std::set<std::string>	Server::split_comma(std::string targets, std::string &duplicate)
{
	std::set<std::string>	splitted_targets;
	std::istringstream		line(targets);
	std::string				s;

	while (getline(line, s, ','))
	{
		if (false == splitted_targets.insert(s).second)
		{
			duplicate = s;
			break;
		}
	}

	return splitted_targets;
}

/*
	Command: PRIVMSG
	Parameters: <channel{,nickname}> <message>

	 The PRIVMSG command allows users to send private messages to other users or to channels.
*/
void	Server::ft_privmsg(Request request)
{
	User*					sender = request.get_user();
	std::string				response;
	usermap::iterator		recipient;
	if (!sender->is_registered())
	{
		response = SERVER_NAME " 462 " + sender->get_nickname() + " :Unauthorized command (not yet registered)";
		send_message(response, sender->get_fd());
		return;
	}
	const std::vector<std::string>& params = request.get_params();
	if (params.empty())
	{
		response = SERVER_NAME " 411 " + sender->get_nickname() + " :No recipient given (PRIVMSG)";
		send_message(response, sender->get_fd());
		return;
	}
	if (params.size() == 1)
	{
		response = SERVER_NAME " 412 " + sender->get_nickname() + " :No text to send";
		send_message(response, sender->get_fd());
		return;
	}
	std::string duplicate_target;
	std::set<std::string> msg_targets = split_comma(params[0], duplicate_target);

	if (!duplicate_target.empty())
	{
		response = SERVER_NAME " 407 " + sender->get_nickname() + " " + duplicate_target + " :Duplicate recipients. No message delivered";
		send_message(response, sender->get_fd());
		return;
	}
	for (std::set<std::string>::const_iterator it = msg_targets.begin(); it != msg_targets.end(); ++it)
	{
		const std::string& target = *it;
		if ((recipient = get_user_by_nick(target)) != _user_map.end())
		{
			send_message(sender->get_prefix() + " PRIVMSG " + target + " :" + params[1], recipient->first);
		}
		else if (_channels.find(target) != _channels.end())
		{
			const std::list<User*>& member_list = _channels[target].getMembers();
			if (std::find(member_list.begin(), member_list.end(), sender) == member_list.end())
			{
				response = SERVER_NAME " 482 " + sender->get_nickname() + " " + target + " :You're not on that channel";
				send_message(response, sender->get_fd());
				return;
			}
			for (std::list<User*>::const_iterator user_it = member_list.begin(); user_it != member_list.end(); ++user_it)
			{
				if (*user_it != sender)
					send_message(sender->get_prefix() + " PRIVMSG " + target + " :" + params[1], (*user_it)->get_fd());
			}
		}
		else
		{
			response = SERVER_NAME " 401 " + sender->get_nickname() + " " + target + " :No such nick/channel";
			send_message(response, sender->get_fd());
			return;
		}
	}
}
