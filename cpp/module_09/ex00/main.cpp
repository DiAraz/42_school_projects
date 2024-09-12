/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:13:14 by daraz             #+#    #+#             */
/*   Updated: 2024/09/12 12:50:52 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

str		trimBlank(const str & str)
{
    size_t first = str.find_first_not_of(' ');
    if (str::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

void	checkInputFile(std::ifstream &file, int argc, char **argv) {
	if (argc != 2)
		throw std::runtime_error("Error: Usage: ./btc [input.txt]");

	file.open(argv[1]);
	if (!file)
		throw std::runtime_error("Error: Could not open file.");

	std::ifstream inputFile(argv[1]);
	std::string currentLine;
	while (std::getline(inputFile, currentLine)) {
		if (currentLine.empty())
			throw std::runtime_error("Error: Empty line in input file.");
	}
}


int	main(int argc, char **argv) {
	std::ifstream		f;
	BitcoinExchange *	ex;
	
	try {
		if (argc != 2) {
			throw std::runtime_error("Error: Usage: ./btc [input.txt]");
		}
		checkInputFile(f, argc, argv);
		ex = new BitcoinExchange(f, argv);
	}
	catch (const std::exception & e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	delete ex;
	return 0;
}
