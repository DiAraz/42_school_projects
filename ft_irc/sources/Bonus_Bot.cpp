/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bonus_Bot.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 08:57:36 by daraz             #+#    #+#             */
/*   Updated: 2024/09/30 08:57:41 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bonus_Bot.hpp"

Bot::Bot(int fd, const std::string& hostmask) : User(fd, const_cast<char*>(hostmask.c_str())) 
{
	set_nickname("BOT");
	set_fullname("BOT");
	set_registered(true);
}

Bot::~Bot(){}