/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:39:21 by daraz             #+#    #+#             */
/*   Updated: 2024/07/14 17:07:57 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
    try {
        Bureaucrat bureaucrat("Camilo", 1);

        std::cout << bureaucrat << std::endl;

        //bureaucrat.incrementGrade();
        bureaucrat.decrementGrade();

        std::cout << "After promotion!" << std::endl;
        std::cout << bureaucrat << std::endl;
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    
    try {
        Bureaucrat bureaucrat("John", 150);

        std::cout << bureaucrat << std::endl;

        bureaucrat.incrementGrade();
        //bureaucrat.decrementGrade();
        
        std::cout << "After promotion!" << std::endl;
        std::cout << bureaucrat << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}