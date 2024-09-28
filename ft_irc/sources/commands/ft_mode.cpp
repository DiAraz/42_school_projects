/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mode.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:49:20 by daraz             #+#    #+#             */
/*   Updated: 2024/09/28 10:34:52 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/Server.hpp"

/*
    Command: MODE
    Parameters: <channel> <+/- option> [<option parameter>]

    The MODE command is used to view or change channel modes (i, t, k, l, o).
*/
void Server::ft_mode(Request request) {
    User* user = request.get_user();
    if (!user->is_registered()) {
        send_message(request, RES_ERR_NOTREGISTERED);
        return;
    }
    std::vector<std::string> params = request.get_params();
    if (params.size() < 1) {
        send_message(request, RES_ERR_NEEDMOREPARAMS);
        return;
    }
    const std::string& channel_name = params[0];
    request.set_channel_name(channel_name);
    if (!Channel::check_correct_channel_name(channel_name)) {
        send_message(request, RES_ERR_BADCHANNAME);
        return;
    }
    channelmap::iterator channelIt = _channels.find(channel_name);
    if (channelIt == _channels.end()) {
        send_message(request, RES_ERR_NOSUCHCHANNEL);
        return;
    }
    if (params.size() == 1) {
        request.set_info(channelIt->second.convert_mode_to_string());
        send_message(request, RES_MODE);
        return;
    }
    for (unsigned int i = 1; i < params.size(); ++i) {
        const std::string& mode_param = params[i];
        char sign = mode_param[0];

        for (std::string::const_iterator it = mode_param.begin(); it != mode_param.end(); ++it) {
            char mode = *it;
            if (mode == '+' || mode == '-') {
                continue;
            }
            if (!channelIt->second.check_correct_mode(mode)) {
                std::cout << "Invalid mode character: |" << mode << "|" << std::endl;
                continue;
            }
            if (std::count(mode_param.begin(), mode_param.end(), mode) > 1) {
                std::cout << "\033[0;31mDuplicate mode detected: " << mode << ", skipping\033[0m" << std::endl;
                continue;
            }
            if (!channelIt->second.check_is_operator(user)) {
                send_message(request, RES_ERR_CHANNOPRIVSNEEDED);
                break;
            }
            std::string param;
            if (Channel::check_valid_mode_param(mode, sign) && i >= params.size() - 1) {
                send_message(request, RES_ERR_NEEDMOREPARAMS);
                continue;
            } else if (Channel::check_valid_mode_param(mode, sign)) {
                param = params[++i];
            }
            if (channelIt->second.handle_mode_options(mode, sign, param, *this, request)) {
                channelIt->second.update_mode(mode, sign);
                std::string updates = std::string(1, sign) + mode;
                if (Channel::check_valid_mode_param(mode, sign)) {
                    updates += " " + param;
                }
                request.set_info(updates);
                broadcast(":" + std::string(SERVER_NAME) + " MODE " + channelIt->second.getName() + " " + updates, NULL, channelIt->second);
            }
        }
    }
}
