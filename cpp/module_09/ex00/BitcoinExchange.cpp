/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:13:07 by daraz             #+#    #+#             */
/*   Updated: 2024/09/10 12:55:14 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructors, Destructor, Operator

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange (std::ifstream & file, char ** av) {
	std::ifstream	data;

	data.open("data.csv", std::ifstream::in);
	this->_handleData(data);

	this->_inputSize = this->_getSize(file) - 1;
	this->_input = new int[this->_inputSize];
	for (int i = 0; i < this->_inputSize; i++)
		this->_input[i] = 0;

	file.open(av[1], std::ifstream::in);
	this->_handleInput(file);

	file.open(av[1], std::ifstream::in);
	this->_output(file);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
	this->_map = src._map;
	this->_inputSize = src._inputSize;
	this->_input = src._input;
}

BitcoinExchange::~BitcoinExchange() {
	delete [] this->_input;
}

BitcoinExchange &	BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	if (this != &rhs) {
		this->_map = rhs._map;
		this->_inputSize = rhs._inputSize;
		this->_input = rhs._input;
	}
	return *this;
}

// Member Functions

int		BitcoinExchange::_getSize(std::ifstream & file) const {
	int	i = 0;
	str	line;

	while (getline(file, line))
		i++;
	
	file.close();
	return i;
}

void	BitcoinExchange::_handleData(std::ifstream & file) {
	str				line, key, value;
	float			f;

	while (std::getline(file, line)) {
		std::istringstream	stream(line);
		
		if (std::getline(stream, key, ',') && std::getline(stream, value, ',')) {
			f = std::atof(value.c_str());
			this->_map.insert(std::make_pair(key, f));
		}
	}
	file.close();
}


void	BitcoinExchange::_handleInput(std::ifstream & file) {
	str	line;
	int	i = 0;
	
	getline(file, line);
	while(getline(file, line)) {
		this->_input[i] = 0;
		if (this->_isPositive(line) == false)
			this->_input[i] = 1;
		if (this->_isDate(line) == false && line.length() < 11)
			this->_input[i] = 2;
		if (this->_isTooLarge(line) == false)
			this->_input[i] = 3;
		i++;
	}
	file.close();
}

bool	BitcoinExchange::_isDate(str line) {
	std::istringstream stream(line); 
	str datePart; 
	char year[5], month[3], day[3];

	getline(stream, datePart, '|');
	datePart = ::trimBlank(datePart);

	year[datePart.copy(year, 4, 0)] = '\0';
	month[datePart.copy(month, 2, 5)] = '\0';
	day[datePart.copy(day, 2, 8)] = '\0';

	if (atoi(year) > 2023 || atoi(month) > 12 || atoi(day) > 31) {
		return false;
	}

	return true;
}


bool	BitcoinExchange::_isPositive(str line) {
	std::istringstream stream(line); 
	str value; 
	size_t found; 
	float numValue;

	getline(stream, value, '|');
	getline(stream, value, '|');

	found = value.find("-");
	found = value.find("-", found + 1);
    
	if (found == str::npos) {
		numValue = atof(value.c_str());
		return (numValue > 0);
	}
	return false;
}


bool	BitcoinExchange::_isTooLarge(str line) {
	std::istringstream stream(line); 
	str value; 
	float numValue;

	getline(stream, value, '|');
	getline(stream, value, '|');

	numValue = atof(value.c_str());
	return (numValue < static_cast<float>(__INT_MAX__));
}


void	BitcoinExchange::_output(std::ifstream & file) {
	str line, key, value;
	int index = 0;

	getline(file, line);
	while (index < this->_inputSize) {
		getline(file, line);

		std::istringstream	s(line);
		getline(s, key, '|'); key = ::trimBlank(key);
		getline(s, value, '|'); value = ::trimBlank(value);

		if (this->_input[index] == 0) {
			if (this->_map[key] == 0) {
				while (this->_map[key] == 0 && key != "Error: year less then 2009.") {
					this->_closestDate(key);
				}
			}
			if (key == "Error: year less then 2009.")
				std::cout << key << std::endl;
			else
				std::cout << key << " => " << value << " = " << atof(value.c_str()) * this->_map[key] << std::endl;
		}
		else if (this->_input[index] == 1)
			std::cout << "Error: not a positive number." << std::endl;
		else if (this->_input[index] == 2)
			std::cout << "Error: bad input => " << key << std::endl;
		else if (this->_input[index] == 3)
			std::cout << "Error: too large a number." << std::endl;

		key.clear();
		value.clear();
		index++;
	}
}

bool BitcoinExchange::_isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int BitcoinExchange::_daysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return _isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}

void BitcoinExchange::_closestDate(str &key) {
    int error = 0;
    char cYear[5], cMonth[3], cDay[3];
    int year, month, day;
    
    key.copy(cYear, 4, 0); cYear[4] = '\0';
    key.copy(cMonth, 2, 5); cMonth[2] = '\0';
    key.copy(cDay, 2, 8); cDay[2] = '\0';

    year = atoi(cYear);
    month = atoi(cMonth);
    day = atoi(cDay);

    if (day > 1) {
        day--;
    } else {
        if (month > 1) {
            month--;
        } else {
            if (year > 2009) {
                year--;
                month = 12;
            } else {
                error = 1;
            }
        }
        day = _daysInMonth(month, year);
    }

    if (error == 1) {
        key = "Error: year less then 2009.";
    } else {
        std::ostringstream newDate;
        newDate << year << "-";
        if (month < 10) newDate << "0";
        newDate << month << "-";
        if (day < 10) newDate << "0";
        newDate << day;

        key = newDate.str();
    }
}