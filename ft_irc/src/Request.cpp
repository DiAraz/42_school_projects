/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 08:57:34 by daraz             #+#    #+#             */
/*   Updated: 2024/09/23 10:22:50 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Request.hpp"

Request::Request(std::string input, User* user)
{
    _user = user;
    _channel_name = "*";
    _info = "*";

    if (!input.empty())
        parse_request(input);
}


std::string Request::get_cmd() const
{
    if (!_cmd.empty())
        return _cmd;
    else
        return "";
}

std::vector<std::string> Request::get_params() const
{
    if (!_params.empty())
        return _params;
    else
        return std::vector<std::string>();
}

User* Request::get_user() const
{
    if (_user != NULL)
        return _user;
    else
        return NULL;
}

void Request::set_user(User* user)
{
    if (user != NULL)
        _user = user;
}

void Request::set_channel_name(const std::string& channelName)
{
    if (!channelName.empty())
        _channel_name = channelName;
}

const std::string& Request::get_channel_name() const
{
    static const std::string default_channel = "*";
    if (!_channel_name.empty())
        return _channel_name;
    else
        return default_channel;
}

void Request::set_info(const std::string& info)
{
    if (!info.empty())
        _info = info;
}

const std::string& Request::get_info() const
{
    static const std::string default_info = "*";
    if (!_info.empty())
        return _info;
    else
        return default_info;
}

void Request::parse_request(std::string input)
{
	size_t first_non_space = input.find_first_not_of(' ');
	if (first_non_space != std::string::npos)
		input = input.substr(first_non_space);
	size_t space_pos = input.find(' ');
	_cmd = (space_pos == std::string::npos) ? input : input.substr(0, space_pos);
	for (size_t i = 0; i < _cmd.size(); ++i)
		_cmd[i] = std::toupper(_cmd[i]);
	if (space_pos == std::string::npos)
		return;
	input = input.substr(space_pos + 1);
	while (!input.empty())
	{
		size_t non_space_pos = input.find_first_not_of(' ');
		if (non_space_pos != std::string::npos)
			input = input.substr(non_space_pos);

		if (!input.empty() && input[0] == ':')
		{
			_params.push_back(input.substr(1));
			break;
		}
		space_pos = input.find(' ');
		if (space_pos == std::string::npos)
		{
			_params.push_back(input);
			break;
		}
		_params.push_back(input.substr(0, space_pos));
		input = input.substr(space_pos + 1);
	}
}

void Request::print_parsed_request()
{
    std::cout << "\n********** Request Summary **********" << std::endl;
    std::cout << "Command Received: [" << _cmd << "]" << std::endl;
    if (!_params.empty())
    {
        std::cout << "Parameters: " << std::endl;
        for (size_t i = 0; i < _params.size(); ++i)
        {
            std::cout << "  Param " << i + 1 << ": {" << _params[i] << "}" << std::endl;
        }
    }
    else
    {
        std::cout << "No Parameters provided." << std::endl;
    }
    std::cout << "**********************************************\n" << std::endl;
}
