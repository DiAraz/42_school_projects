/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:14:28 by daraz             #+#    #+#             */
/*   Updated: 2024/09/20 15:14:31 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <map>

class Channel;

class User
{
	private:	
		std::string		_name;
		std::string		_nickname;
		std::string 	_fullname;
		std::string		_hostmask;
		int				_fd;
		bool			_registered;
		bool			_pass_provided;
		bool			_operator_status;
		std::map<std::string, Channel *> _channels;
		
	public:
		std::string		buff;
		
		User();
		User( const User & user );
		User(int fd, char *hostmask);

		std::string get_name() const;
		std::string get_nickname() const;
		std::string get_fullname() const;
		std::string get_hostmask() const;
		std::string get_prefix() const;
		const std::map<std::string, Channel *> &getChannels ( void ) const;
		std::map<std::string, Channel *> &getChannels( int );
		int get_fd() const;
		bool is_registered() const;
		bool is_pass_provided() const;
		bool is_operator() const;
	
		void set_name(std::string name);
		void set_nickname(std::string nickname);
		void set_fullname(std::string fullname);
		void set_operator(bool value);
		void set_registered(bool value);
		void set_pass_provided(bool value);

		void input_append(std::string input);
};

bool operator==(const User & lhs, const User & rhs);
