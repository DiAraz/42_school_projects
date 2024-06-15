/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:11:24 by daraz             #+#    #+#             */
/*   Updated: 2024/06/15 15:42:25 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) 
                        : _name(name), _weapon(weapon) {}

HumanA::~HumanA(){}

void    HumanA::attack(void) const {
    if (!(this->_weapon.getType().empty())) {
        std::cout << _name << " attacks with their " << this->_weapon.getType() << std::endl;
    } else {
        std::cout << _name << " attacks with their hidden weapon" << std::endl;
    }
}