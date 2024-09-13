/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:44:20 by daraz             #+#    #+#             */
/*   Updated: 2024/09/13 16:10:59 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	if (ac < 3)
		return std::cout << "Error: Usage: ./sort <random integers>" << std::endl, 1;
	
	std::vector<int>	input;
	std::set<int>		seenNumbers;
	int					nb;
	int					i;
	
	for (i = 1; av[i] != NULL; i++) {
		for (int j = 0; av[i][j] != '\0'; j++) {
			if (!isdigit(av[i][j]))
				return std::cout << "Error" << std::endl, 1;
		}
		nb = atoi(av[i]);
		if (nb < 0)
			return std::cout << "Error" << std::endl, 1;
		
		if (seenNumbers.find(nb) != seenNumbers.end()) {
			return std::cout << "Error: Duplicates are not allowed." << std::endl, 1;
		}
		input.push_back(nb);
		seenNumbers.insert(nb);
	}

	std::vector<int>::iterator	it;
	std::vector<int>::iterator	ite = input.end();

	std::cout << "Before: ";
	for (it = input.begin(); it != ite; it++)
		std::cout << " " << *it;
	std::cout << std::endl;
	
	PmergeMe	merge(input, i - 1);

	return 0;
}
