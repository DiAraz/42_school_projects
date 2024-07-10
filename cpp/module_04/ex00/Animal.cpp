/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:37:18 by daraz             #+#    #+#             */
/*   Updated: 2024/07/06 13:51:33 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Animal default constructor called." << std::endl;
	return ;
}

Animal::Animal(Animal const & src)
{
	std::cout << "Animal copy constructor called." << std::endl;
	*this = src;
	return ;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal type constructor called." << std::endl;
	return ;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called." << std::endl;
	return ;
}

Animal &	Animal::operator=(Animal const & src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

std::string    Animal::getType(void) const
{
    return this->_type;
}

void	Animal::makeSound(void) const
{
	std::cout << this->_type << " - Default sound!" << std::endl;
	return ;
}