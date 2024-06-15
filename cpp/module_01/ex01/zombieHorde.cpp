/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:28:47 by daraz             #+#    #+#             */
/*   Updated: 2024/06/15 13:44:14 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*    zombieHorde( int N, std::string name ) {
    
    Zombie *horde = new Zombie[N];
    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
    }
    return horde;
}