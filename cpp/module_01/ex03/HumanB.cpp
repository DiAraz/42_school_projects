/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:13:06 by daraz             #+#    #+#             */
/*   Updated: 2024/06/15 15:48:02 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) {
    this->_name = name;
    this->_weapon = NULL;
}

HumanB::~HumanB() {}

void    HumanB::setWeapon(Weapon& weapon) {
    this->_weapon = &weapon;
}

void    HumanB::attack( void ) const {
    if (this->_weapon != NULL && this->_weapon->getType() != "") {
        std::cout << _name << " attacks with their " << this->_weapon->getType() << std::endl;
    } else {
        std::cout << _name << " didn't get any weapon to attack." << std::endl;
    }
}