/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:12:53 by daraz             #+#    #+#             */
/*   Updated: 2024/09/10 12:55:19 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <cstdlib>

typedef std::string str;

template <typename T>
std::string itos(T nb) {
	std::ostringstream	ss;
	ss << nb;
	return ss.str();
}

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(std::ifstream & file, char ** av);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange();

		BitcoinExchange &	operator=(BitcoinExchange const &rhs);

	private:
		std::map<str, float>	_map;
		int						_inputSize;
		int *					_input;
		str const				_inputPath;

        bool    _isLeapYear(int year);
        int     _daysInMonth(int month, int year);
		int		_getSize(std::ifstream & file) const;
		void	_handleData(std::ifstream & file);
		void	_handleInput(std::ifstream & file);
		bool	_isDate(str line);
		bool	_isPositive(str line);
		bool	_isTooLarge(str line);
		void	_output(std::ifstream & file);
		void	_closestDate(str & key);
};

str 		trimBlank(const str & str);