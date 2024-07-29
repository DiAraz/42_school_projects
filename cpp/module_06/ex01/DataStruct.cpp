/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataStruct.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:47:02 by daraz             #+#    #+#             */
/*   Updated: 2024/07/29 12:10:51 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataStruct.hpp"

uintptr_t	serialize(Data * ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *		deserialize(uintptr_t src)
{
	return (reinterpret_cast<Data *>(src));
}

std::ostream &	operator<<(std::ostream & os, const Data & obj)
{
	os	<< "\n\t- Number value : " << obj.numberValue
		<< "\n\t- String value : " << obj.stringValue << std::endl;
	return (os);
}