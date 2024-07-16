/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:48:32 by daraz             #+#    #+#             */
/*   Updated: 2024/07/16 15:31:01 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ) : AForm( "ShrubberyCreationForm", 145, 137 ), _target( target ) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& src ) : AForm( src ), _target( src._target ) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(
									ShrubberyCreationForm const & src)
{
	this->_target = src._target;
	return (*this);
}

void    ShrubberyCreationForm::execute( const Bureaucrat& executor ) const {
    if ( this->getSigned() == false )
        throw AForm::NotSignedException();
    else if ( executor.getGrade() > this->getGradeToExecute() ) {
        throw AForm::GradeTooLowException();
    }

    std::ofstream	ofs;

	ofs.open((this->_target + "_shrubbery").c_str(),
								std::ofstream::out | std::ofstream::app);
	if (ofs.is_open())
	{
		ofs << ShrubberyCreationForm::_shrubbery;
		std::cout << "A shrubbery was created in "
				<< _target << "_shrubbery." << std::endl;
		ofs.close();
	}
}

std::string const ShrubberyCreationForm::_shrubbery =
"\n"
"            \\ /   \n"
"          -->*<--\n"
"            /_\\    \n"
"           /_\\_\\  \n"
"          /_/_/_\\  \n"
"          /_\\_\\_\\ \n"
"         /_/_/_/_\\ \n"
"         /_\\_\\_\\_\\\n"
"        /_/_/_/_/_\\\n"
"        /_\\_\\_\\_\\_\\\n"
"       /_/_/_/_/_/_\\\n"
"       /_\\_\\_\\_\\_\\_\\\n"
"      /_/_/_/_/_/_/_\\\n"
"           [___]\n\n";