/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invite.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:43:46 by daraz             #+#    #+#             */
/*   Updated: 2024/09/29 12:55:27 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/Server.hpp"

/*
	Command: INVITE
	Parameters: <nickname> <channel>

	The INVITE command in IRC is used to invite a user to join a specific channel.
	This command allows users, particularly channel operators,
	to invite others into channels they may not have access to (especially if the channel is invite-only).
*/
void Server::ft_invite(Request request)
{
	if (request.get_params().size() < 2)
	{
		send_message(request, RES_ERR_NEEDMOREPARAMS);
		return;
	}
	std::string nickname = request.get_params()[0];
	std::string channelName = request.get_params()[1];

	User* inviter = request.get_user();
	if (!inviter->is_registered())
	{
		send_message(request, RES_ERR_NOTREGISTERED);
		return;
	}

	if (!Channel::check_correct_channel_name(channelName))
	{
		request.set_channel_name(channelName);
		send_message(request, RES_ERR_BADCHANNAME);
		return;
	}

	channelmap::iterator channelIt = _channels.find(channelName);
	if (channelIt == _channels.end())
		return;

	Channel& channel = channelIt->second;

	if (!channel.check_is_member(inviter))
	{
		request.set_channel_name(channel.getName());
		send_message(request, RES_ERR_NOTONCHANNEL);
		return;
	}

	usermap::iterator invitedIt = get_user_by_nick(nickname);
	if (invitedIt == _user_map.end())
	{
		request.set_info(nickname);
		send_message(request, RES_ERR_NOSUCHNICK);
		return;
	}

	User* invitedUser = &(invitedIt->second);
	if (channel.check_is_member(invitedUser))
	{
		send_message(request, RES_ERR_CHANNELALREADYJOINED);
		return;
	}

	if (channel.check_has_mode('i') && !channel.check_is_operator(inviter))
	{
		request.set_channel_name(channel.getName());
		request.set_info(inviter->get_nickname());
		send_message(request, RES_ERR_CHANNOPRIVSNEEDED);
		return;
	}
	
	invitedUser->set_invite_status(true);
	std::string inviteMessage = ":" + inviter->get_nickname() + "!" + inviter->get_nickname() + "@" + SERVER_NAME +
	                            " INVITE " + invitedUser->get_nickname() + " :" + channelName;
	send_message(inviteMessage, invitedUser->get_fd());

	std::string confirmMessage = SERVER_NAME ": 341 " + inviter->get_nickname() + " " + invitedUser->get_nickname() + " " + channelName;
	send_message(confirmMessage, inviter->get_fd());
}
