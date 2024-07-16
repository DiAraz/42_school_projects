/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:37:20 by daraz             #+#    #+#             */
/*   Updated: 2024/07/16 14:47:16 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target ) : AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src ) : AForm(src), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &	RobotomyRequestForm::operator=(
									RobotomyRequestForm const & src)
{
	this->_target = src._target;
	return (*this);
}

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if ( executor.getGrade() > this->getGradeToExecute() )
        throw AForm::GradeTooLowException();
    else {
        std::cout << "* Bzzzzzzzzzzzzzzzzzzzzzz! *" << std::endl;
        if (std::rand() % 2)
            std::cout << this->_target << " has been robotomized!" << std::endl;
        else
            std::cout << this->_target << " robotomization failed..." << std::endl;
    }
}