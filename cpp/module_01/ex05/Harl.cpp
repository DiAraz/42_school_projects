/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:54:09 by daraz             #+#    #+#             */
/*   Updated: 2024/06/17 13:44:09 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl () {}

Harl::~Harl () {}

void	Harl::_debug(void)
{
	std::cout << std::endl
		<< "I love having extra bacon for my "
		"7XL-double-cheese-triple-pickle-specialketchup burger. "
		"I really do!"
		<< std::endl;
}

void	Harl::_info(void)
{
	std::cout << std::endl
		<< "I cannot believe adding extra bacon costs more money. "
		"You didn't put enough bacon in my burger! If you did, "
		"I wouldn't be asking for more!"
		<< std::endl;
}

void	Harl::_warning(void)
{
	std::cout << std::endl
		<< "I think I deserve to have some extra bacon for free. "
		"I've been coming for years whereas you started working here "
		"since last month."
		<< std::endl;
}

void	Harl::_error(void)
{
	std::cout << std::endl
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

void Harl::complain(std::string level)
{
    typedef void (Harl::*fptr)(void);
    
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    fptr complaints[4] = { &Harl::_debug, &Harl::_info,
                           &Harl::_warning, &Harl::_error };
    
    int i = 0;
    while (i < 4)
    {
        if (levels[i] == level)
        {
            (this->*complaints[i])();
            return;
        }
        i++;
    }
    
    if (level == "EXIT") {
        std::cout << std::endl << "Good bye!" << std::endl << std::endl;
        return;
    }
    else {
        std::cout << std::endl << "Provide a valid level or choose EXIT" << std::endl; 
        return;
    }
}
