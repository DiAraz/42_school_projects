/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:01:11 by daraz             #+#    #+#             */
/*   Updated: 2024/07/03 14:11:48 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;

    std::cout << "FragTrap " << this->_name << " constructed!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->_name << " deconstructed!" << std::endl;
}

void    FragTrap::highFive(void) {
    if (this->_hitPoints == 0) {
		std::cout << this->_name << " is broken. Can't High Fives everyone." << std::endl;
    }
    else if (this->_energyPoints == 0) {
        std::cout << "FragTrap " << this->_name << " is out of energy. Can't High Fives everyone." << std::endl;
    }
    else {
        std::cout << "FragTrap " << this->_name << " High Fives everyone!" << std::endl;
        this->_energyPoints -= 1;
    }
    return ;
}