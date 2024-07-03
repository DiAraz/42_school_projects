/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:46:20 by daraz             #+#    #+#             */
/*   Updated: 2024/07/02 13:53:51 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>

int	main(void) {

    ClapTrap clap("Rusty");
    ClapTrap trap("Shiny");

    clap.attack("Shiny");
    trap.takeDamage(8);
    trap.beRepaired(2);
    trap.takeDamage(20);
    trap.takeDamage(5);
    trap.beRepaired(50);
	return (0);
}