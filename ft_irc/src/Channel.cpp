/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 08:57:40 by daraz             #+#    #+#             */
/*   Updated: 2024/09/23 16:26:29 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Channel.hpp"

Channel::Channel() {
	_name = "*";
	_topic = "*";
	_modes = t_mode;
	_password = "*";
	_limit = -1;
}

Channel::Channel(const std::string &name, const std::string &password) {
	_name = name.empty() ? "*" : name;
	_password = password.empty() ? "*" : password;
	_topic = "*";
	_modes = t_mode;
	_limit = -1;
	std::cout << "Created new channel: [" << _name 
	          << "] with password: [" << _password << "]" << std::endl;
}

Channel::Channel(const Channel &channel) {
    _name = channel.getName();
    _topic = channel.getTopic();
    _modes = channel.getModes();
    _password = channel.getPassword();
    _limit = channel.getLimit();

    for (std::list<User *>::const_iterator memberIt = channel.getMembers().begin();
         memberIt != channel.getMembers().end(); ++memberIt) {
        _members.push_back(*memberIt);
    }
    for (std::list<User *>::const_iterator opsIt = channel.getOps().begin();
         opsIt != channel.getOps().end(); ++opsIt) {
        _ops.push_back(*opsIt);
    }
}

Channel::~Channel() {}

Channel &Channel::operator=(const Channel &channel) {
    if (this != &channel) {
        _name = channel.getName();
        _password = channel.getPassword();
        _topic = channel.getTopic();
        _modes = channel.getModes();

        _members.clear();
        for (std::list<User *>::const_iterator memberIt = channel.getMembers().begin();
             memberIt != channel.getMembers().end(); ++memberIt) {
            add_member(*memberIt);
        }
        _ops.clear();
        for (std::list<User *>::const_iterator opsIt = channel.getOps().begin();
             opsIt != channel.getOps().end(); ++opsIt) {
            _ops.push_back(*opsIt);
        }
    }
    return *this;
}

int Channel::getLimit() const { 
	return this->_limit; 
}

short Channel::getModes() const { 
	return this->_modes; 
}

const std::string& Channel::getName() const { 
	return this->_name; 
}

const std::string& Channel::getTopic() const { 
	return this->_topic; 
}

const std::string& Channel::getPassword() const { 
	return this->_password; 
}

const std::list<User*>& Channel::getMembers() const { 
	return this->_members; 
}

std::list<User*>& Channel::getMembers(int) { 
	return this->_members; 
}

const std::list<User*>& Channel::getOps() const { 
	return this->_ops; 
}

std::list<User*>& Channel::getOps(int) { 
	return this->_ops; 
}

void Channel::setLimit(int limit) {
	this->_limit = limit;
}

void Channel::setTopic(const std::string& topic) {
	if (!topic.empty()) {
		this->_topic = topic;
	}
}

void Channel::setPassword(const std::string& password) {
	if (!password.empty()) {
		this->_password = password;
	}
}

void Channel::add_member(User* user) {
	if (!check_is_member(user)) {
		_members.push_back(user);
		if (_members.size() == 1) {
			add_operator(user);
		}
	}
}

int Channel::remove(User* user) {
	_members.remove(user);
	operator_remove(user);
	return _members.empty() ? 1 : 0;
}

void Channel::add_operator(User* op) {
	if (!check_is_operator(op)) {
		_ops.push_back(op);
	}
}

short choose_mode(char mode) {
	switch (mode) {
		case 'i': return i_mode;
		case 't': return t_mode;
		case 'k': return k_mode;
		case 'o': return o_mode;
		case 'l': return l_mode;
		default:  return 0;
	}
}

void Channel::update_mode(char mode, char sign)
{

	short mode_flag = choose_mode(mode);

	if (sign == '+') {
		_modes |= mode_flag;
	} else if (sign == '-') {
		_modes &= ~mode_flag;
	}
}

bool Channel::check_correct_channel_name(const std::string &name) {
	if (name.empty() || name[0] != '#') 
		return false;

	for (size_t i = 0; i < name.size(); ++i) {
		if (name[i] == ' ' || name[i] == ',' || name[i] == '\a')
			return false;
	}
	return true;
}

bool Channel::check_correct_mode(char mode)
{
	return (std::string("itkol").find_first_of(mode) != std::string::npos);
}

bool Channel::check_valid_mode_param(char mode, char sign)
{
	if (mode == 'o' || ((mode == 'l' || mode == 'k') && sign == '+'))
		return (true);
	return (false);
}


bool Channel::check_is_member( User *user ) const
{
	return (std::find (_members.begin (), _members.end (), user) != _members.end ());
}

bool Channel::check_is_operator( User *user ) const
{
	return (std::find (_ops.begin (), _ops.end (), user) != _ops.end ());
}

bool Channel::check_has_mode( char mode ) const
{
	return (_modes & choose_mode(mode));
}

User* Channel::getMember(const std::string& nickname) {
	for (std::list<User*>::iterator it = _members.begin(); it != _members.end(); ++it) {
		if ((*it)->get_nickname() == nickname) {
			return *it;
		}
	}
	return NULL;
}

std::string Channel::convert_mode_to_string() const
{
	std::string mString = "+";

	for (short mode = i_mode; mode <= l_mode; mode <<= 1)
	{
		switch (mode)
		{
			case i_mode:
				if (_modes & i_mode)
					mString += 'i';
				break;
			case t_mode:
				if (_modes & t_mode)
					mString += 't';
				break;
			case k_mode:
				if (_modes & k_mode)
					mString += 'k';
				break;
			// case o_mode:
			// 	if (_modes & o_mode)
			// 		mString += 'o';
			// 	break;
			case l_mode:
				if (_modes & l_mode)
					mString += 'l';
				break;
			default:
				break;
		}
	}

	return mString;
}

