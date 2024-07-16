/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:39:24 by daraz             #+#    #+#             */
/*   Updated: 2024/07/15 10:15:19 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    public:
        Bureaucrat( const std::string& name, int grade );
        Bureaucrat( const Bureaucrat& src );
        ~Bureaucrat();
        Bureaucrat& operator=( const Bureaucrat& rhs );

        std::string getName() const;
        int         getGrade() const;
        void        incrementGrade();
        void        decrementGrade();

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
        int                 _grade;
        Bureaucrat();

};

std::ostream&   operator<<( std::ostream& o, const Bureaucrat& rhs );

#endif