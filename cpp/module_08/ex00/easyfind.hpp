/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:40:00 by daraz             #+#    #+#             */
/*   Updated: 2024/09/03 10:52:05 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _EASYFIND_HPP_
#define _EASYFIND_HPP_

#include <iostream>
#include <algorithm>
#include <list>

template <typename T>
void    easyfind(T& cont, int number)
{
    if ( std::find(cont.begin(), cont.end(), number) != cont.end() )
        std::cout << "Number found in the container." << std::endl;
    else
        std::cout << "Number not found in the container." << std::endl;
}

#endif