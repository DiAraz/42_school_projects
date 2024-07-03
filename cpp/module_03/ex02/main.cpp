/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:46:20 by daraz             #+#    #+#             */
/*   Updated: 2024/07/03 14:14:39 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {

    /* ClapTrap clap("Rusty");
    ClapTrap trap("Shiny");

    clap.attack("Shiny");
    trap.takeDamage(8);
    trap.beRepaired(2);
    trap.takeDamage(20);
    trap.takeDamage(5);
    trap.beRepaired(50); */

    /* ScavTrap scavTrap("Holly");

    scavTrap.attack("Rusty");
    scavTrap.takeDamage(10);
    scavTrap.beRepaired(10);
    scavTrap.guardGate();
    scavTrap.takeDamage(200);
    scavTrap.beRepaired(100);
    scavTrap.guardGate(); */

    FragTrap fragTrap("Emily");

    fragTrap.attack("Rusty");
    fragTrap.takeDamage(10);
    fragTrap.beRepaired(10);
    fragTrap.highFive();
    fragTrap.takeDamage(200);
    fragTrap.beRepaired(100);
    fragTrap.highFive();
	return (0);
}