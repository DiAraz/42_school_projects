/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:39:12 by daraz             #+#    #+#             */
/*   Updated: 2024/09/28 10:33:32 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/Server.hpp"

/*
    Command: LIST
    Parameters: [<channel>]

    The LIST command in IRC is used to retrieve a list of channels or information about specific channels. 
*/
void Server::ft_list(Request request)
{
	User *user = request.get_user();
	if (!user->is_registered())
	{
		send_message(request, RES_ERR_NOTREGISTERED);
		return;
	}
	bool specificChannelsRequested = (request.get_params().size() > 0);
	if (specificChannelsRequested)
	{
		send_message(request, RES_RPL_LISTSTART);
	}
	std::set<std::string> reqChannels;
	if (specificChannelsRequested)
	{
		std::string dup;
		reqChannels = split_comma(request.get_params()[0], dup);
	}
	for (Server::channelmap::const_iterator channelIt = _channels.begin(); channelIt != _channels.end(); ++channelIt)
	{
		bool shouldSendChannelInfo = !specificChannelsRequested || reqChannels.find(channelIt->first) != reqChannels.end();
		if (shouldSendChannelInfo)
		{
			std::ostringstream stream;
			stream << channelIt->second.getMembers().size();
			std::string channelInfo = channelIt->first + " " + stream.str() + " :" + channelIt->second.getTopic();
			request.set_info(channelInfo);
			send_message(request, RES_RPL_LIST);
		}
	}
	send_message(request, RES_RPL_LISTEND);
}
