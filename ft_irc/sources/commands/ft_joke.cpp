/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joke.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:52:04 by daraz             #+#    #+#             */
/*   Updated: 2024/09/30 11:07:36 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Server.hpp"

/*
	Command: JOKE
	Parameters: <BOT/bot>

	The TIME BOT command is used to request bot to tell a joke.
*/
void Server::ft_joke(Request request)
{
    Bot joke_bot(-1, "BOT");
    User *user = request.get_user();

    if (!request.get_params().empty() && (request.get_params()[0] == "BOT" || request.get_params()[0] == "bot"))
    {
        std::cout << "BOT RESPONSE [JOKE] " << std::endl;
        std::string jokes[] = {
            "Why do programmers prefer dark mode? Because the light attracts bugs!",
            "Why do Java developers wear glasses? Because they don't C#.",
            "How many programmers does it take to change a lightbulb? None, that's a hardware problem.",
            "What is a programmer’s favorite hangout place? The Foo Bar!"
        };

        srand(time(0));
        int random_index = rand() % 4;
        std::string selected_joke = jokes[random_index];

        std::string joke_message = user->get_nickname() + ", here's a joke for you: " + selected_joke;
        send_message(joke_bot.get_prefix() + " PRIVMSG " + user->get_nickname() + " :" + joke_message, user->get_fd());
    }
    else
    {
        send_message(joke_bot.get_prefix() + " PRIVMSG " + user->get_nickname() + " :Error: Invalid BOT command", user->get_fd());
    }
}