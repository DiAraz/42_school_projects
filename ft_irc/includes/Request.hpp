/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:15:02 by daraz             #+#    #+#             */
/*   Updated: 2024/09/21 14:58:45 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "User.hpp"

# include <vector>
# include <string>
# include <iostream>

class Request
{
	private:
		User						*_user;
		std::string					_cmd;
		std::vector<std::string>	_params;
		std::string					_channel_name;
		std::string					_info;
		void parse_request(std::string(input));
	
	public:
		Request(std::string input, User *user);
		std::string					get_cmd() const;
		std::vector<std::string>	get_params() const;
		User						*get_user() const;
		const 						std::string &get_channel_name( void ) const;
		const 						std::string &get_info( void ) const;
		void						set_user(User *user);
		void						set_channel_name( const std::string & channelName );
		void						set_info( const std::string & info );
		void 						print_parsed_request();
};