/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:54:16 by daraz             #+#    #+#             */
/*   Updated: 2024/06/17 12:55:51 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
	private:
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);

	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
};

#endif