/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:33:48 by daraz             #+#    #+#             */
/*   Updated: 2024/07/10 10:28:49 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include "Brain.hpp"
#include <iostream>

class AAnimal
{
    public:
        AAnimal( void );
        AAnimal( std::string type );
        AAnimal( const AAnimal& src );
        AAnimal& operator=( const AAnimal& src );
        virtual ~AAnimal( void );

        virtual void    makeSound( void ) const = 0;;
        std::string     getType( void ) const; 

    protected:
        std::string _type;
};

#endif