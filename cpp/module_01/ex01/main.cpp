/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:06:58 by daraz             #+#    #+#             */
/*   Updated: 2024/06/15 13:41:37 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*    zombieHorde( int N, std::string name );

int main( void ) {

    int numberOfZombies = 5;
    
    Zombie *horde = zombieHorde(numberOfZombies, "noNameZombi");

    for (int i = 0; i < numberOfZombies; i++) {
        horde[i].announce();
    }

    delete [] horde;
    return 0;
}