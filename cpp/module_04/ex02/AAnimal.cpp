/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:37:18 by daraz             #+#    #+#             */
/*   Updated: 2024/07/10 10:29:09 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("AAnimal")
{
	std::cout << "AAnimal default constructor called." << std::endl;
	return ;
}

AAnimal::AAnimal(AAnimal const & src)
{
	std::cout << "AAnimal copy constructor called." << std::endl;
	*this = src;
	return ;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "AAnimal type constructor called." << std::endl;
	return ;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called." << std::endl;
	return ;
}

AAnimal &	AAnimal::operator=(AAnimal const & src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

std::string    AAnimal::getType(void) const
{
    return this->_type;
}

void	AAnimal::makeSound(void) const
{
	std::cout << this->_type << " - Default sound!" << std::endl;
	return ;
}