/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_who.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 09:58:39 by daraz             #+#    #+#             */
/*   Updated: 2024/09/27 10:20:27 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Server.hpp"

/*
	Command: WHO
	Parameters: [<channel>] [<nickname>]

	The WHO command provides information about users on the server or specific channels.
*/
void Server::ft_who(Request request)
{
	std::map<std::string, User *> usersToShow;
	usermap::iterator userIt;
	channelmap::iterator channelIt;
	std::list<User *>::const_iterator channelUserIt;
	std::map<std::string, User *>::const_iterator usersToShowIt;

	if (request.get_params().empty())
	{
		for (userIt = _user_map.begin(); userIt != _user_map.end(); ++userIt)
			usersToShow[userIt->second.get_nickname()] = &userIt->second;
	}
	else if (Channel::check_correct_channel_name(request.get_params()[0]))
	{
		std::string channelName = request.get_params()[0];
		request.set_channel_name(channelName);

		channelIt = _channels.find(channelName);
		if (channelIt == _channels.end())
			return send_message(request, RES_ERR_NOSUCHCHANNEL);
		for (channelUserIt = channelIt->second.getMembers().begin();
		     channelUserIt != channelIt->second.getMembers().end(); ++channelUserIt)
		{
			usersToShow[(*channelUserIt)->get_nickname()] = *channelUserIt;
		}
	}
	else
	{
		userIt = get_user_by_nick(request.get_params()[0]);
		request.set_info(request.get_params()[0]);

		if (userIt == _user_map.end())
			return send_message(request, RES_ERR_NOSUCHNICK);

		usersToShow[userIt->second.get_nickname()] = &userIt->second;
	}
	for (usersToShowIt = usersToShow.begin(); usersToShowIt != usersToShow.end(); ++usersToShowIt)
	{
		User *user = usersToShowIt->second;
		std::string whoReply = " " + user->get_name() + " " + user->get_hostmask() + " " + SERVER_NAME +
		                       " " + user->get_nickname();
		if (!request.get_params().empty() &&
		    Channel::check_correct_channel_name(request.get_params()[0]) &&
		    channelIt->second.check_is_operator(user))
		{
			whoReply += " @";
		}
		whoReply += " :0 " + user->get_fullname();
		request.set_info(whoReply);
		send_message(request, RES_RPL_WHOREPLY);
	}
	send_message(request, RES_RPL_ENDOFWHO);
}
