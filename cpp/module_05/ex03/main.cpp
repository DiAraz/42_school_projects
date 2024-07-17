/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:39:21 by daraz             #+#    #+#             */
/*   Updated: 2024/07/17 13:51:58 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{
    Intern  newbyIntern;
    Bureaucrat camillo("Camillo", 1);
    AForm*   form;

    try
	{
		//form = newbyIntern.makeForm("robotomy", "Bender");
        form = newbyIntern.makeForm("robotomy request", "Bender"); 
		camillo.signForm(*form);
		camillo.executeForm(*form);
		delete (form);
	}
	catch (std::exception & e)
	{
		std::cout << ": " << e.what() << std::endl;
	}
        
    return 0;
}
