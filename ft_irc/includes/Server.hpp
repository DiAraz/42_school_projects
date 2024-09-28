/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:14:40 by daraz             #+#    #+#             */
/*   Updated: 2024/09/28 10:24:53 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <fcntl.h>
# include <map>
# include <algorithm>
# include <sstream>
# include <utility>
# include <ctime>
# include <numeric>
# include <set>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netdb.h>
# include <arpa/inet.h>
# include <sys/wait.h>
# include <poll.h>
# include <signal.h>
# include <string>
# include <iostream>
# include "response.hpp"
# include "User.hpp"
# include "Request.hpp"
# include "Channel.hpp"

# define MAXLINE 4096
# define SERVER_NAME ":ircproject42.com"
# define RESPONSE_END "\r\n" //IRC standard ending
# define VERSION "1.0"

//OPER Credentials
# define OPER_PASS "42"
# define OPER_LOG "admin"

class Server
{
	typedef std::map<int, User>				usermap;
	typedef std::map<std::string, Channel>	channelmap;

	private:
		int					_port;
		std::string			_password;
		std::string			_creation_time;
		int					_listening_socket;
		pollfd				_user_map_poll[SOMAXCONN];
		nfds_t				_fd_count;
		usermap				_user_map;
		channelmap			_channels;

	public:
	
		Server(char **argv);
		int get_port();
		const channelmap &getChannels( void ) const;
		Channel *find_channel(std::string channel_name);
		std::string get_password();

		void server_loop();
		void socket_construction();
		void accept_new_client();
		void handle_client_request(int i);
		void add_client_to_poll(int user_fd);
		void remove_client_from_poll(int user_fd);
		void process_command(char* cmd, int user_fd);
		void command_exec(Request request);
		void remove_client(User *user, std::string s);
		void print_login(User *user);
		usermap::iterator	get_user_by_nick(std::string nickname);
		std::set<std::string>	split_comma(std::string targets, std::string &duplicate);

		// --- commands
		void ft_cap(Request request);
		void ft_ping(Request request);
		void ft_nick(Request request);
		void ft_user(Request request);
		void ft_pass(Request request);
		void ft_privmsg(Request request);
		void ft_quit(Request request);
		void join_names_command (Request request);
		void ft_list (Request request);
		void ft_topic (Request request);
		void ft_part (Request request);
		void ft_who (Request request);
		void ft_mode (Request request);
		void ft_oper(Request request);
		void ft_kill(Request request);
		void ft_notice(Request request);
		void ft_globops(Request request);
		static void send_message(std::string, int fd);
		static void send_message(Request req, t_res err);
		void ft_kick(Request request);
		void ft_invite(Request request);
		
		void send_names_list(Request &request, Channel &channel);
		static void broadcast (std::string message, User* user, Channel& channel);

		// -------------- Exceptions -------------------
		class IncorrectPortNumber: public std::exception {
			const char * what() const throw() {
				return "Error: Provided portnumber is incorrect.";
			}
		};

		class InvalidPassword: public std::exception {
			const char * what() const throw() {
				return "Error: Provided password is invalid.";
			}
		};

		class CreateSocketError: public std::exception {
			const char * what() const throw() {
				return "Error: Creating socket failed.";
			}
		};

		class SetSocketOptionError: public std::exception {
			const char * what() const throw() {
				return "Error: Setting socket options failed.";
			}
		};

		class BindSocketError: public std::exception {
			const char * what() const throw() {
				return "Error: Adding User failed, too many Users connected.";
			}
			};

			class ListenSocketError: public std::exception {
			const char * what() const throw() {
				return "Error: Listening failed.";
			}
		};

		class AcceptSocketError: public std::exception {
			const char * what() const throw() {
				return "Error: Accepting failed.";
			}
		};

		class RecieveMessageFailed: public std::exception {
			const char * what() const throw() {
				return "Error: Recieving the message failed.";
			}
		};

		class FdPollFullError: public std::exception {
		const char * what() const throw() {
			return "Error: Adding User failed, too many Users connected.";
		}
		};

		class PollFailedError: public std::exception {
			const char * what() const throw() {
				return "Error: The poll() function failed.";
			}
		};
};