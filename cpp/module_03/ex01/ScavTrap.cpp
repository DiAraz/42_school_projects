/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:16:07 by daraz             #+#    #+#             */
/*   Updated: 2024/07/03 13:33:49 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;

    std::cout << "ScavTrap " << this->_name << " constructed!" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->_name << " deconstructed!" << std::endl;
}

void    ScavTrap::attack(std::string const& target) {
    
    if (this->_hitPoints == 0) {
		std::cout << "ScavTrap " << _name
			<< " can't attack, it is out of hit points." << std::endl;
		return ;
	}
    if (this->_energyPoints == 0) {
        std::cout << "ScavTrap " << this->_name << " can't attack, it is out of energy!" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints -= 1;
}

void    ScavTrap::guardGate() {
    if (this->_hitPoints == 0)
		std::cout << this->_name
			<< " is broken. Can't go in Gate keeper mode." << std::endl;
	else
		std::cout << this->_name
			<< " is now in Gate keeper mode." << std::endl;
	return ;
}