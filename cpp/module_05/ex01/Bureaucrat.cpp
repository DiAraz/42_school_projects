/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:39:26 by daraz             #+#    #+#             */
/*   Updated: 2024/07/15 11:10:14 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//Constructors
Bureaucrat::Bureaucrat(const std::string& name, int grade ) : _name(name), _grade(grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade) {}

Bureaucrat::~Bureaucrat() {}

// Operators overloads

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
    if ( this != &src )
        _grade = src.getGrade();
    return *this;
}

std::ostream& operator<<( std::ostream& o, const Bureaucrat& rhs ) {
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return o;
}

// Getters
std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

// Member functions

void    Bureaucrat::signForm( Form& form ) {
    try {
        form.beSigned( *this );
        std::cout << *this << " signed " << form.getName() << std::endl;
    } catch (Form::GradeTooLowException &e) {
        std::cout << _name << " coulnd't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::incrementGrade() {
    if ( _grade - 1 < 1 )
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void    Bureaucrat::decrementGrade() {
    if ( _grade + 1 > 150 )
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

// Exceptions
const char *	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Can not increment. Grade is too low.");	
}

const char *	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Can not decrement. Grade is too high.");
}