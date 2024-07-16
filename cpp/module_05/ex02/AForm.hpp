/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:13:32 by daraz             #+#    #+#             */
/*   Updated: 2024/07/16 15:22:52 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string> 

class Bureaucrat;

class AForm
{

    public:
        AForm( const std::string& name, int gradeToSign, int gradeToExecute );
        AForm( const AForm& src );
        ~AForm();
        AForm&   operator=( const AForm& rhs );

        std::string         getName() const;
        bool                getSigned() const;
        int                 getGradeToSign() const;
        int                 getGradeToExecute() const;
        virtual void        execute( const Bureaucrat& executor ) const = 0;
        void                beSigned( const Bureaucrat& bureaucrat );

        class GradeTooHighException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

        class NotSignedException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExecute;

        AForm();
    
};

std::ostream&   operator<<( std::ostream& o, const AForm& rhs );

#endif