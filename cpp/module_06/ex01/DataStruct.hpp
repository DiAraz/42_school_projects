/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataStruct.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:47:05 by daraz             #+#    #+#             */
/*   Updated: 2024/07/29 12:09:16 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DATASTRUCT_HPP_
# define _DATASTRUCT_HPP_

# include <string>
# include <stdint.h>
# include <iostream>

//structure
struct Data
{
	unsigned int	numberValue;
	std::string		stringValue;
};

//member functions
uintptr_t		serialize(Data * ptr);
Data *			deserialize(uintptr_t src);

//stream overload
std::ostream &	operator<<(std::ostream &stream, const Data & obj);

#endif