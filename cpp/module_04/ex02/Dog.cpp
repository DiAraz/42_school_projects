/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:53:07 by daraz             #+#    #+#             */
/*   Updated: 2024/07/10 10:32:18 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
    this->_brain = new Brain();
}

Dog::Dog(const Dog& src) : AAnimal(), _brain(NULL)
{
    *this = src;
}

Dog::~Dog( void )
{
    std::cout << "Dog destructor called" << std::endl;
    delete  this->_brain;
}

Dog& Dog::operator=( const Dog& src )
{
    if (this != &src)
    {
        if (this->_brain != NULL)
			delete (this->_brain);
        this->_brain = new Brain(*src._brain);
        this->_type = src._type;
    }
    return (*this);
}

void    Dog::makeSound( void ) const
{
    std::cout << this->_type << " - Haaf!" << std::endl;
}