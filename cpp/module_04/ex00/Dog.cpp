/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:53:07 by daraz             #+#    #+#             */
/*   Updated: 2024/07/06 13:54:57 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog( void )
{
    std::cout << "Dog destructor called" << std::endl;
}

void    Dog::makeSound( void ) const
{
    std::cout << this->_type << " - Haaf!" << std::endl;
}