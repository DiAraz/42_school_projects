/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:39:04 by daraz             #+#    #+#             */
/*   Updated: 2024/07/17 13:51:15 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {

    public:
            Intern();
            Intern(const Intern& src);
            ~Intern();

            Intern& operator=(const Intern& src);

            AForm*   makeForm(std::string name, std::string target);

            class InvalidFormName : public std::exception {
			public:
				virtual const char *	what(void) const throw() { return "Incorrect form name"; }
		    };

    private:
		typedef struct	sForms
		{
			std::string const &	formName;
			AForm *	(*function)(std::string const &);
		}	forms;
};

#endif