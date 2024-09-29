/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:03:45 by daraz             #+#    #+#             */
/*   Updated: 2024/09/29 12:50:05 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../includes/User.hpp"

User::User()
	: _name("*"),
	  _nickname("*"),
	  _fullname("*"),
	  _hostmask(""),
	  _fd(-1),
	  _registered(false),
	  _pass_provided(false),
	  _operator_status(false),
	  _invite_status(false){}

User::User(int fd, char *hostmask)
	: _name("*"),
	  _nickname("*"),
	  _fullname("*"),
	  _hostmask(hostmask ? hostmask : ""),
	  _fd(fd),
	  _registered(false),
	  _pass_provided(false),
	  _operator_status(false),
	  _invite_status(false){}


User::User(const User& user)
	: _name(user.get_name()),
	  _nickname(user.get_nickname()),
	  _fullname(user.get_fullname()),
	  _hostmask(user.get_hostmask()),
	  _fd(user.get_fd()),
	  _registered(user.is_registered()),
	  _pass_provided(user.is_pass_provided()),
	  _invite_status(user.is_invited()),
	  _channels(user._channels){}


bool operator==(const User & lhs, const User & rhs)
{
	if (lhs.get_nickname () == rhs.get_nickname ())
		return (true);
	return (false);
}

std::string User::get_name() const{ 
	return _name;
}
std::string User::get_nickname() const{
	return _nickname;
}
std::string User::get_fullname() const{ 
	return _fullname;
}
std::string User::get_hostmask() const{ 
	return _hostmask;
}

//Returns a prefix string in IRC format :nickname!name@hostmask.

std::string User::get_prefix() const	{ return ":" + _nickname + "!" + _name + "@" + _hostmask; }

int User::get_fd() const{ 
	return _fd;
}

const std::map<std::string, Channel *> &User::getChannels (void) const
{
	return (_channels);
}

std::map<std::string, Channel *> &User::getChannels(int) //allows modification
{
	return (_channels);
}

bool User::is_registered() const{
	 return _registered;
}
bool User::is_pass_provided() const{ 
	return _pass_provided;
}
bool User::is_operator() const{ 
	return _operator_status;
}

bool User::is_invited() const{
	return _invite_status;
}

void User::set_name(std::string name){ 
	_name = name; 
}
void User::set_nickname(std::string nickname){
	_nickname = nickname; 
}
void User::set_fullname(std::string fullname){ 
	_fullname = fullname; 
}
void User::set_registered(bool value){ 
	_registered = value; 
}
void User::set_operator(bool value){ 
	_operator_status = value; 
}

void User::set_invite_status(bool value) {
	_invite_status = value;
}

void User::set_pass_provided(bool value){ 
	_pass_provided = value; 
}

void User::input_append(std::string input)
{
	buff.append(input);
}
