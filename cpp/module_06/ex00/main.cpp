/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:01:13 by daraz             #+#    #+#             */
/*   Updated: 2024/07/25 15:40:15 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int	main(int ac, char **av) {
	if (ac != 2)
	{
		std::cout << "Usage: ./convert parameter" << std::endl;
		return (0);
	}
	
	Converter::convert(av[1]);

	return 0;
}