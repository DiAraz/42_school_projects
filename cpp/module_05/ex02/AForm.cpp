/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:13:35 by daraz             #+#    #+#             */
/*   Updated: 2024/07/16 15:22:36 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructors & Destructor
AForm::AForm( const std::string& name, int gradeToSign, int gradeToExecute ) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if ( gradeToSign < 1 || gradeToExecute < 1 )
        throw AForm::GradeTooHighException();
    if ( gradeToSign > 150 || gradeToExecute > 150 )
        throw AForm::GradeTooLowException();
}

AForm::AForm( const AForm& src ) : _name( src.getName() ), _gradeToSign( src.getGradeToSign() ), _gradeToExecute( src.getGradeToExecute() ) {}

AForm::~AForm() {}

// Operator overloads
AForm&   AForm::operator=( const AForm& rhs ) {
    if ( this != &rhs )
        _signed = rhs.getSigned();
    return *this;
}

std::ostream&   operator<<( std::ostream& o, const AForm& rhs ) {
    o << "Form name: " << rhs.getName() << std::endl
      << "Grade to sign: " << rhs.getGradeToSign() << std::endl
      << "Grade to execute: " << rhs.getGradeToExecute();
    return o;
}

// Getters
std::string AForm::getName() const {
    return _name;
}

bool   AForm::getSigned() const {
    return _signed;
}

int   AForm::getGradeToSign() const {
    return _gradeToSign;
}

int   AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

// Member function
void    AForm::beSigned(const Bureaucrat& bureaucrat) {
    if ( bureaucrat.getGrade() > _gradeToSign )
        throw AForm::GradeTooLowException();
    _signed = true;
}

// Exceptions
const char *	AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high.");	
}

const char *	AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low.");
}

const char *	AForm::NotSignedException::what(void) const throw()
{
	return ("Form is not signed.");
}