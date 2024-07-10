/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:32:41 by daraz             #+#    #+#             */
/*   Updated: 2024/07/07 14:36:51 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain constructor called." << std::endl;
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called." << std::endl;
}

Brain::Brain(const Brain& src)
{
    *this = src;
}

Brain& Brain::operator=(const Brain& src)
{
    if ( this != &src ) {
        for (int i = 0; i < 100; i++) {
            this->_ideas[i] = src._ideas[i];
        }
    }
    return *this;
}