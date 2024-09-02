/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:36:47 by daraz             #+#    #+#             */
/*   Updated: 2024/09/02 12:18:07 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template<typename T>
void	iter(T *adress, int lenght, void (*fct)(T& var)) {
	for (int i = 0; i < lenght; i++)
		fct(adress[i]);
}

template<typename T>
void	printParam(T &val) {
	std::cout << val << " ";
}

int	main() {
	char	array1[] = {'h', 'e', 'l', 'l', 'o'};
	iter(array1, 5, printParam<char>);
	std::cout << std::endl << std::endl;

	int	array2[] = {1, 2, 3, 4};
	iter(array2, 4, printParam<int>);
	std::cout << std::endl << std::endl;

	float	array3[] = {2.1, 2.2, 2.3, 2.4};
	iter(array3, 4, printParam<float>);
}