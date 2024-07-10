/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:49:37 by daraz             #+#    #+#             */
/*   Updated: 2024/07/10 10:32:06 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
    this->_brain = new Brain();
}

Cat::Cat(const Cat& src) : AAnimal(), _brain(NULL)
{
    *this = src;
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
    delete  this->_brain;
}

Cat& Cat::operator=(const Cat& src)
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

void    Cat::makeSound(void) const
{
    std::cout << this->_type << " - Meoooooow!" << std::endl;
}