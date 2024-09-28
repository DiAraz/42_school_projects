/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_topic.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:07:20 by daraz             #+#    #+#             */
/*   Updated: 2024/09/28 10:33:32 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/Server.hpp"

/*
    Command: TOPIC
    Parameters: <channel> [<topic>]

    In IRC, the TOPIC command allows users to view or set the topic of a channel.
*/
void Server::ft_topic(Request request)
{
	if (request.get_params().empty())
	{
		send_message(request, RES_ERR_NEEDMOREPARAMS);
		return;
	}
	std::string channel_name = request.get_params()[0];
	request.set_channel_name(channel_name);
	channelmap::iterator channel_it = _channels.find(channel_name);
	if (channel_it == _channels.end())
	{
		send_message(request, RES_ERR_NOSUCHCHANNEL);
		return;
	}

	Channel& channel = channel_it->second;
	if (request.get_params().size() == 1)
	{
		if (channel.getTopic().empty() || channel.getTopic() == "*")
			send_message(request, RES_RPL_NOTOPIC);
		else
		{
			request.set_info(channel.getTopic());
			send_message(request, RES_RPL_TOPIC);
		}
		return;
	}
	std::string new_topic = request.get_params()[1];
	if (!channel.check_has_mode('t') || channel.check_is_operator(request.get_user()))
	{
		channel.setTopic(new_topic);
	}
	else
	{
		send_message(request, RES_ERR_CHANNOPRIVSNEEDED);
		return;
	}
	request.set_info(channel.getTopic());
	send_message(request, RES_RPL_TOPIC);

	std::ostringstream response;
	response << static_cast<int>(RES_RPL_TOPIC);
	broadcast(":" + std::string(SERVER_NAME) + " " + response.str() + " "
			  + request.get_user()->get_nickname() + " "
			  + request.get_channel_name() + " :" + request.get_info(),
			  request.get_user(), channel);
}
