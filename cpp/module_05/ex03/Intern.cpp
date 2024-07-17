/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:38:57 by daraz             #+#    #+#             */
/*   Updated: 2024/07/17 13:51:22 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern( const Intern& src ) {
    *this = src;
}

Intern::~Intern() {}

Intern& Intern::operator=( const Intern& rhs ) {
    ( void ) rhs;
    return (*this);
}

static AForm *	makePresidentialPardonForm(std::string const & target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *	makeRobotomyRequestForm(std::string const & target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *	makeShrubberyCreationForm(std::string const & target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *	Intern::makeForm(std::string name, std::string target)
{
	AForm *	newForm = NULL;
	static forms const	forms[3] = 
		{
			{"shrubbery creation", makeShrubberyCreationForm},
			{"robotomy request", makeRobotomyRequestForm},
			{"presidential pardon", makePresidentialPardonForm}
		};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i].formName == name)
		{
			newForm = forms[i].function(target);
			std::cout << "Intern creates " << *newForm << std::endl;
			return (newForm);
		}
	}
	std::cout << "Intern could't create form \""
		<< name << "\"";
	throw Intern::InvalidFormName();
}