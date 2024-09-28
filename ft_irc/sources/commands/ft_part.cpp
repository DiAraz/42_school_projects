/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:23:44 by daraz             #+#    #+#             */
/*   Updated: 2024/09/28 10:33:32 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/Server.hpp"

/*
	Command: PART
	Parameters: <channel,channels> [<reason>]

	PART command allows users to leave a specified channel (or channels) and optionally provide a reason for leaving. 
*/
void Server::ft_part(Request request)
{
	std::string dup;
	if (request.get_params().empty())
	{
		send_message(request, RES_ERR_NEEDMOREPARAMS);
		return;
	}
	std::set<std::string> channelNames = split_comma(request.get_params()[0], dup);
	if (channelNames.empty())
	{
		send_message(request, RES_ERR_NEEDMOREPARAMS);
		return;
	}
	if (request.get_params().size() > 1)
		request.set_info(request.get_params()[1]);
	for (std::set<std::string>::iterator it = channelNames.begin(); it != channelNames.end(); ++it)
	{
		const std::string &channelName = *it;
		request.set_channel_name(channelName);
		if (!Channel::check_correct_channel_name(channelName))
		{
			send_message(request, RES_ERR_BADCHANNAME);
			continue;
		}
		channelmap::iterator channelIt = _channels.find(channelName);
		if (channelIt == _channels.end())
		{
			send_message(request, RES_ERR_NOSUCHCHANNEL);
			continue;
		}
		if (request.get_user()->getChannels(0).find(channelName) == request.get_user()->getChannels(0).end())
		{
			request.set_info("");
			send_message(request, RES_ERR_NOTONCHANNEL);
			continue;
		}
		channelIt->second.remove(request.get_user());
		request.get_user()->getChannels(0).erase(channelName);
		if (!channelIt->second.getMembers().empty())
		{
			broadcast(
				":" + request.get_user()->get_nickname() + "!" +
				request.get_user()->get_nickname() + "@" + SERVER_NAME + " PART " +
				channelName + " :" + request.get_info(),
				request.get_user(),
				channelIt->second);
		}
		else
		{
			_channels.erase(channelIt);
			std::cout << "Channel " << channelName << " deleted." << std::endl;
		}
		send_message(request, RES_CHANNELLEFT);
	}
}