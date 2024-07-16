/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:37:17 by daraz             #+#    #+#             */
/*   Updated: 2024/07/16 15:13:44 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
#include <iostream>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(RobotomyRequestForm const & src);
		RobotomyRequestForm(std::string const & target);
		~RobotomyRequestForm(void);

		RobotomyRequestForm &	operator=(RobotomyRequestForm const & src);

		void        execute( const Bureaucrat& executor ) const;

	private:
		std::string	_target;

        RobotomyRequestForm(void);
};

#endif
