/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:58:26 by daraz             #+#    #+#             */
/*   Updated: 2024/07/06 14:01:59 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type( "WrongAnimal" ) {
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : _type( type )
{
    std::cout << "WrongAnimal type constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& src )
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = src;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& src )
{
    if ( this != &src ) {
        this->_type = src._type;
    }
    return (*this);
}

void WrongAnimal::makeSound( void ) const
{
    std::cout << this->_type << " - Default sound!" << std::endl;
}

std::string    WrongAnimal::getType( void ) const
{
    return this->_type;
}