/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:46:26 by daraz             #+#    #+#             */
/*   Updated: 2024/07/03 13:35:35 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{

    public:
        ClapTrap(std::string name);
        ~ClapTrap();

        ClapTrap(const ClapTrap &);
        ClapTrap &operator=(const ClapTrap& src);

        void    attack(std::string const& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        
    protected:
    
        std::string     _name;
        unsigned int    _hitPoints;
        unsigned int    _energyPoints;
        unsigned int    _attackDamage;

        ClapTrap();

};

#endif