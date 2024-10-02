/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:14:54 by daraz             #+#    #+#             */
/*   Updated: 2024/10/02 12:01:54 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* Official IRC responses */

typedef enum e_res
{
	RES_ERR_NEEDMOREPARAMS = 461,
	RES_ERR_NOSUCHCHANNEL = 403,
	RES_ERR_NOTONCHANNEL = 442,
	RES_ERR_CHANNOPRIVSNEEDED = 482,
	RES_ERR_BADCHANNAME = 479,
	RES_ERR_NOTREGISTERED = 451,
	RES_ERR_BADCHANNELKEY = 475,
	RES_ERR_BANNEDFROMCHAN = 474,
	RES_ERR_CHANNELISFULL = 471,
	RES_RPL_LISTSTART = 321,
	RES_RPL_LIST = 322,
	RES_RPL_LISTEND = 323,
	RES_RPL_CHANNELMODEIS = 324,
	RES_RPL_NOTOPIC = 331,
	RES_RPL_TOPIC = 332,
	RES_ERR_NOSUCHNICK = 401,
	RES_RPL_ENDOFWHO = 315,
	RES_RPL_WHOREPLY = 352,
	RES_ERR_USERSDONTMATCH = 502,
	RES_ERR_USERNOTINCHANNEL = 441,
	RES_ERR_UNKNOWNMODE = 472,
	RES_ERR_CHANNELALREADYJOINED = 1000,
	RES_CHANNELJOINED = 1001,
	RES_CHANNELLEFT = 1002,
	RES_MODE = 1003,
	RES_ERR_USERONCHANNEL = 443,
	RES_ERR_USERNOTREGISTERED = 451,
	RES_ERR_INVITEONLYCHAN = 473,
	RES_INVITED = 341,
	RES_ERR_NOTANOPERATOR = 1004,
	RES_ERR_ALREADYANOPERATOR = 1005,
	RES_ERR_USERISRECEIVER = 1100,
	RES_ERR_NOFILEPROVIDED = 1101,
	RES_ERR_FILENOTCREATED = 1102	
}	t_res;
