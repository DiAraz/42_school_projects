/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:33:48 by daraz             #+#    #+#             */
/*   Updated: 2024/07/10 10:29:01 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "Brain.hpp"
#include <iostream>

class Animal
{
    public:
        Animal( void );
        Animal( std::string type );
        Animal( const Animal& src );
        Animal& operator=( const Animal& src );
        virtual ~Animal( void );

        virtual void    makeSound( void ) const;
        std::string     getType( void ) const; 

    protected:
        std::string _type;
};

#endif
