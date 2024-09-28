/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:15:09 by daraz             #+#    #+#             */
/*   Updated: 2024/09/23 16:25:39 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <list>
# include <vector>
# include <algorithm>

# include "User.hpp"
# include "response.hpp"
# include "Request.hpp"

enum Modes
{
	i_mode = 1,
	t_mode = 2,
	k_mode = 4,
	o_mode = 8,
	l_mode = 16,
};

class Server ;

class Channel
{
	private:
		std::string			_name;
		std::string			_topic;
		short				_modes;
		std::string			_password;
		std::list<User *>	_members;
		std::list<User *>	_ops;
		int					_limit;
		
	public:
		Channel( void );
		Channel( const Channel & channel );
		Channel( const std::string & name, const std::string & password );
		Channel &operator=( const Channel & channel );
		~Channel( void );
		
		short getModes( void ) const;
		int   getLimit( void ) const;
		const std::string &getName( void ) const;
		const std::string &getTopic( void ) const;
		const std::string &getPassword( void ) const;
		const std::list<User *> &getMembers( void ) const;
		std::list<User *> &getMembers( int );
		const std::list<User *> &getOps( void ) const;
		std::list<User *> &getOps( int );
		void setTopic( const std::string & topic );
		void setLimit( int limit );
		void setPassword( const std::string & password );
		void add_member( User * user );
		int remove( User *user );
		void add_operator( User * op );
		void operator_remove( User * op );
		void update_mode (char mode, char sign);
		bool handle_mode_options (char mode, char sign, std::string param, const Server & server, Request request);
		static bool check_correct_channel_name( const std::string & name );
		static bool check_correct_mode(char mode);
		static bool check_valid_mode_param(char mode, char sign);
		bool check_is_member(User *user) const;
		bool check_is_operator(User *user) const;
		bool check_has_mode (char mode ) const;
		User *getMember( const std::string & nickame );
		std::string convert_mode_to_string( void ) const;
};
