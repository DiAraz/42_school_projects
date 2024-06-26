/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:06:58 by daraz             #+#    #+#             */
/*   Updated: 2024/06/15 13:24:16 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void    randomChump( std::string name );

int main( void ) {
  
    std::cout << "Paulo - zombie on stack." << std::endl;
    
    Zombie paulo( "Paulo" );
    paulo.announce();

    std::cout << "Lena - zombie on heap." << std::endl;
    Zombie *lena = newZombie( "Lena" );
    lena->announce();
    delete lena;

    std::cout << "Chump - zombie from randomChump()." << std::endl;
    randomChump( "Chump" );
    
    return 0;
}