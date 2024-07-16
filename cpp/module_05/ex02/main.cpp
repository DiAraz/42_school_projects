/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:39:21 by daraz             #+#    #+#             */
/*   Updated: 2024/07/16 15:33:18 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{

    try {
        Bureaucrat camillo("Camillo", 5);
        ShrubberyCreationForm form1("Christmas tree");
        RobotomyRequestForm form2("Robotomy");
        PresidentialPardonForm form3("President");

        std::cout << "\n--------------- Shrubbery Form ---------------" << std::endl;
        camillo.signForm(form1);
        camillo.executeForm(form1);
        std::cout << "\n--------------- Robotomy Form ---------------" << std::endl;
        camillo.signForm(form2);
        camillo.executeForm(form2);
        std::cout << std::endl;
        camillo.executeForm(form2);
        std::cout << std::endl;
        camillo.executeForm(form2);
        std::cout << std::endl;
        camillo.executeForm(form2);
        std::cout << "\n--------------- President Form ---------------" << std::endl;
        camillo.signForm(form3);
        camillo.executeForm(form3);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}