/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:56:10 by daraz             #+#    #+#             */
/*   Updated: 2024/09/12 15:38:46 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN () {}

RPN::RPN(char* input) {
	int number1, number2, result = 0;
	int digitCount = 0, signCount = 0;

	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] == ' ') continue;
		if (isdigit(input[i])) 
			digitCount++;
		else if (input[i] == '*' || input[i] == '/' || input[i] == '+' || input[i] == '-')
			signCount++;
	}

	if (signCount != digitCount - 1) 
		throw std::runtime_error("Syntax Error: Invalid number of operators, enter one digit more than signs.");

	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] == ' ') continue;

		if (isdigit(input[i])) {
			this->_stack.push(input[i] - '0');
		}
		else if (input[i] == '*' || input[i] == '/' || input[i] == '+' || input[i] == '-') {
			number2 = this->_stack.top(); this->_stack.pop();
			number1 = this->_stack.top(); this->_stack.pop();

			if (input[i] == '*')
				result = number1 * number2;
			else if (input[i] == '/')
				result = number1 / number2;
			else if (input[i] == '+')
				result = number1 + number2;
			else if (input[i] == '-')
				result = number1 - number2;

			this->_stack.push(result);
		}
		else {
			std::cerr << "Error" << std::endl;
			return;
		}
	}
	std::cout << result << std::endl;
}


RPN::RPN(RPN const &src) {
	this->_stack = src._stack;
	*this = src;
}

RPN::~RPN() {}

RPN &	RPN::operator=(RPN const &rhs) {
	if (this != &rhs) {
		this->_stack = rhs._stack;
	}
	return *this;
}