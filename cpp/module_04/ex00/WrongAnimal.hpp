/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:56:27 by daraz             #+#    #+#             */
/*   Updated: 2024/07/06 13:57:51 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal( void );
        WrongAnimal( std::string type );
        WrongAnimal( const WrongAnimal& src );
        WrongAnimal& operator=( const WrongAnimal& src );
        ~WrongAnimal( void );

        void            makeSound( void ) const;
        std::string     getType( void ) const;

    protected:
        std::string _type;
};

#endif