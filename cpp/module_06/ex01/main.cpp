/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:01:13 by daraz             #+#    #+#             */
/*   Updated: 2024/07/29 12:15:06 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataStruct.hpp"
#include <iostream>

int	main(void)
{
	Data data = {42, "Prague"};
	
	uintptr_t	serialized = serialize(&data);
	Data *		deserialized = deserialize(serialized);

	std::cout << "Before deserialization: " << data << std::endl;
	
	std::cout << "Unsigned integer pointer: "
		<< serialized << std::endl << std::endl;
		
	std::cout << "After deserialization: " << *deserialized << std::endl;
	
	return (0);
}