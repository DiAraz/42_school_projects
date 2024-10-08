/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error_replies.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 08:57:24 by daraz             #+#    #+#             */
/*   Updated: 2024/10/02 16:44:34 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Server.hpp"

void Server::send_message(Request req, t_res err)
{
    std::ostringstream stream;
    stream << static_cast<int>(err);

    if (err == RES_ERR_UNKNOWNMODE) {
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " " 
            + req.get_channel_name() + " :unknown mode",
            req.get_user()->get_fd()
        );
    } else if (err == RES_ERR_BADCHANNAME) {
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " " 
            + req.get_channel_name() + " :bad channel name",
            req.get_user()->get_fd()
        );
    } else if (err == RES_ERR_INVITEONLYCHAN) {
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " " 
            + req.get_channel_name() + " :Cannot join channel (+i)",
            req.get_user()->get_fd()
        );
    } else if (err == RES_RPL_LISTSTART) {
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " Channel: Users Name",
            req.get_user()->get_fd()
        );
    } else if (err == RES_RPL_LIST) {
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " " 
            + req.get_info(),
            req.get_user()->get_fd()
        );
    } else if (err == RES_RPL_LISTEND) {
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " End of /LIST",
            req.get_user()->get_fd()
        );
    } else if (err == RES_ERR_NOSUCHNICK) {
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " " 
            + req.get_info() + " :No such nick",
            req.get_user()->get_fd()
        );
    } else if (err == RES_ERR_CHANNOPRIVSNEEDED) {
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " " 
            + req.get_channel_name() + " :You're not an operator",
            req.get_user()->get_fd()
        );
    } else if (err == RES_RPL_WHOREPLY) {
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " " 
            + req.get_channel_name() + " " + req.get_info(),
            req.get_user()->get_fd()
        );
    } else if (err == RES_RPL_ENDOFWHO) {
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " " 
            + req.get_channel_name() + " :End of /WHO list.",
            req.get_user()->get_fd()
        );
    } else if (err == RES_RPL_TOPIC) {
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " " 
            + req.get_channel_name() + " :" + req.get_info(),
            req.get_user()->get_fd()
        );
    } else if (err == RES_RPL_NOTOPIC) {
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " " 
            + req.get_channel_name() + " :no topic is set",
            req.get_user()->get_fd()
        );
    } else if (err == RES_ERR_BADCHANNELKEY) {
        stream.str("");
        stream << static_cast<int>(RES_ERR_BADCHANNELKEY);
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " " 
            + req.get_channel_name() + " :password is incorrect",
            req.get_user()->get_fd()
        );
    } else if (err == RES_ERR_BANNEDFROMCHAN) {
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " " 
            + req.get_channel_name() + " :permission denied. Have you provided the password?",
            req.get_user()->get_fd()
        );
    } else if (err == RES_ERR_NOSUCHCHANNEL) {
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " " 
            + req.get_channel_name() + " :no such channel",
            req.get_user()->get_fd()
        );
    } else if (err == RES_ERR_NEEDMOREPARAMS) {
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " " 
            + req.get_cmd() + " :not enough parameters",
            req.get_user()->get_fd()
        );
    } else if (err == RES_ERR_CHANNELISFULL) {
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " " 
            + req.get_channel_name() + " :Cannot join channel (+l)",
            req.get_user()->get_fd()
        );
    } else if (err == RES_ERR_NOTREGISTERED) {
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " :You have not registered",
            req.get_user()->get_fd()
        );
    } else if (err == RES_MODE) {
        send_message(
            ":" + std::string(SERVER_NAME) + " MODE " 
            + req.get_channel_name() + " " + req.get_info(),
            req.get_user()->get_fd()
        );
    } else if (err == RES_ERR_CHANNELALREADYJOINED) {
        stream.str("");
        stream << static_cast<int>(RES_ERR_BADCHANNAME);
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " " 
            + req.get_channel_name() + " :" + req.get_info() + " :already on channel",
            req.get_user()->get_fd()
        );
    } else if (err == RES_ERR_NOTONCHANNEL) {
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " " 
            + req.get_channel_name() + " :You're not on that channel",
            req.get_user()->get_fd()
        );
    } else if (err == RES_ERR_USERNOTINCHANNEL) {
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " " 
            + req.get_info() + " " 
            + req.get_channel_name() + " :They aren't on the channel",
            req.get_user()->get_fd()
        );
    } else if (err == RES_ERR_NOTANOPERATOR) {
        stream.str("");
        stream << static_cast<int>(RES_ERR_CHANNOPRIVSNEEDED);
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " " 
            + req.get_channel_name() + " :" + req.get_info() + " is not an operator",
            req.get_user()->get_fd()
        );
    } else if (err == RES_ERR_ALREADYANOPERATOR) {
        stream.str("");
        stream << static_cast<int>(RES_ERR_USERSDONTMATCH);
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " " 
            + req.get_channel_name() + " :" + req.get_info() + " is already an operator",
            req.get_user()->get_fd()
        );
    } else if (err == RES_CHANNELLEFT) {
        send_message(
            ":" + req.get_user()->get_nickname() + "!" 
            + req.get_user()->get_name() + "@" + SERVER_NAME + " PART " 
            + req.get_channel_name() + " :" + req.get_info(),
            req.get_user()->get_fd()
        );
    } else if (err == RES_CHANNELJOINED) {
        send_message(
            ":" + req.get_user()->get_nickname() + "!" 
            + req.get_user()->get_name() + "@" + SERVER_NAME + " JOIN :" 
            + req.get_channel_name(),
            req.get_user()->get_fd()
        );
    } else if (err == RES_ERR_USERISRECEIVER) {
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " " 
            + ":You cannot send files to yourself",
            req.get_user()->get_fd()
        );
    } else if (err == RES_ERR_NOFILEPROVIDED) {
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " " 
            + ":Could not open file",
            req.get_user()->get_fd()
        );
    } else if (err == RES_ERR_FILENOTCREATED) {
        send_message(
            ":" + std::string(SERVER_NAME) + " " + stream.str() + " " 
            + req.get_user()->get_nickname() + " " 
            + ":Failed to create file on server",
            req.get_user()->get_fd()
        );
    }
	else {
		send_message (
				":" + std::string (SERVER_NAME)
				+ " " + req.get_user ()->get_nickname ()
				+ " :an error occurred", req.get_user ()->get_fd ());
	}
}
