/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:13:32 by daraz             #+#    #+#             */
/*   Updated: 2024/07/15 11:09:36 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string> 

class Bureaucrat;

class Form
{

    public:
        Form( const std::string& name, int gradeToSign );
        Form( const std::string& name, int gradeToSign, int gradeToExecute );
        Form( const Form& src );
        ~Form();
        Form&   operator=( const Form& rhs );

        std::string getName() const;
        bool        getSigned() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;
        void        beSigned( const Bureaucrat& bureaucrat );

        class GradeTooHighException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExecute;

        Form();
    
};

std::ostream&   operator<<( std::ostream& o, const Form& rhs );

#endif