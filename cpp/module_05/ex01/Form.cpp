/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:13:35 by daraz             #+#    #+#             */
/*   Updated: 2024/07/15 11:10:02 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors & Destructor
Form::Form( const std::string& name, int gradeToSign ) : _name( name ), _gradeToSign( gradeToSign ), _gradeToExecute( 0 ) {
    if ( gradeToSign < 1 )
        throw Form::GradeTooHighException();
    if ( gradeToSign > 150 )
        throw Form::GradeTooLowException();
}

Form::Form( const Form& src ) : _name( src.getName() ), _gradeToSign( src.getGradeToSign() ), _gradeToExecute( src.getGradeToExecute() ) {}

Form::~Form() {}

// Operator overloads
Form&   Form::operator=( const Form& rhs ) {
    if ( this != &rhs )
        _signed = rhs.getSigned();
    return *this;
}

std::ostream&   operator<<( std::ostream& o, const Form& rhs ) {
    o << "Form name: " << rhs.getName() << std::endl
      << "Grade to sign: " << rhs.getGradeToSign() << std::endl
      << "Grade to execute: " << rhs.getGradeToExecute();
    return o;
}

// Getters
std::string Form::getName() const {
    return _name;
}

bool   Form::getSigned() const {
    return _signed;
}

int   Form::getGradeToSign() const {
    return _gradeToSign;
}

int   Form::getGradeToExecute() const {
    return _gradeToExecute;
}

// Member function
void    Form::beSigned(const Bureaucrat& bureaucrat) {
    if ( bureaucrat.getGrade() > _gradeToSign )
        throw Form::GradeTooLowException();
    _signed = true;
}

// Exceptions
const char *	Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high.");	
}

const char *	Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low.");
}