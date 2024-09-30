/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 08:59:49 by daraz             #+#    #+#             */
/*   Updated: 2024/09/30 10:51:11 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Server.hpp"

/*
	Command: TIME
	Parameters: <BOT/bot>

	The TIME BOT command is used to request bot to show the current time.
*/
void Server::ft_time(Request request)
{
    Bot time_bot(-1, "BOT");
    User *user = request.get_user();

    if (!request.get_params().empty() && (request.get_params()[0] == "BOT" || request.get_params()[0] == "bot"))
    {
        std::cout << "BOT RESPONSE [TIME] " << std::endl;
        time_t now = time(0);
        char *time_str;
        time_str = ctime(&now);

        std::string time_message = user->get_nickname() + ", the current time is: " + std::string(time_str);
        send_message(time_bot.get_prefix() + " PRIVMSG " + user->get_nickname() + " :" + time_message, user->get_fd());
        return;
    }
    else
    {
        send_message(time_bot.get_prefix() + " PRIVMSG " + user->get_nickname() + " :Error: Invalid BOT command", user->get_fd());
    }
}