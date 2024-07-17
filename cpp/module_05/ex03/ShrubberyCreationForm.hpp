/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:48:25 by daraz             #+#    #+#             */
/*   Updated: 2024/07/16 15:07:19 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		ShrubberyCreationForm(std::string const & target);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & src);

		void        execute( const Bureaucrat& executor ) const;

	private:
		std::string					_target;
        static std::string const	_shrubbery;

        ShrubberyCreationForm(void);
};

#endif