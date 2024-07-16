/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:39:21 by daraz             #+#    #+#             */
/*   Updated: 2024/07/15 11:15:45 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{

    try {
        Bureaucrat john("John",11);
        Form examForm("Exam Request", 10);

        john.signForm(examForm);

        std::cout << examForm << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    
    try {
        Bureaucrat camillo("Camillo",9);
        Form examForm("Exam Request", 10);

        camillo.signForm(examForm);

        std::cout << examForm << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}