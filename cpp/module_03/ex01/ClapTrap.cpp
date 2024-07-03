/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:46:29 by daraz             #+#    #+#             */
/*   Updated: 2024/07/02 13:53:27 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    std::cout << "ClapTrap " << _name << " constructed!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap " << _name << " deconstructed!" << std::endl;
    return;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    *this = src;
    std::cout << "ClapTrap copy constructed!" << std::endl;
    return;
}

ClapTrap&   ClapTrap::operator=( const ClapTrap& src ) {
    this->_name = src._name;
    this->_hitPoints = src._hitPoints;
    this->_energyPoints = src._energyPoints;
    this->_attackDamage = src._attackDamage;
    return *this;
}

void    ClapTrap::attack(std::string const& target)
{
    if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name
			<< " can't attack, it is out of hit points." << std::endl;
		return ;
	}
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " can't attack, it is out of energy!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints -= 1;
}

void    ClapTrap::takeDamage( unsigned int amount )
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " can't take anymore damage!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount << " damage!" << std::endl;
    if ((int)_hitPoints - (int)amount <= 0) {
        _hitPoints = 0;
    }
    else 
        _hitPoints -= amount;
}

void    ClapTrap::beRepaired( unsigned int amount )
{
    if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name
			<< " can not be repaired, it is broken!" << std::endl;
		return ;
	}
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " can not be repaired, it is out of energy!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points!" << std::endl;
    _energyPoints -= 1;
    _hitPoints += amount;
}