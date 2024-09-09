/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:36:47 by daraz             #+#    #+#             */
/*   Updated: 2024/09/03 10:52:54 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main() {
	std::list<int>	lst;

	lst.push_back(8);
	lst.push_back(4);
	lst.push_back(42);
	lst.push_back(6);

	easyfind(lst, 7);
	easyfind(lst, 6);

	return 0;
}