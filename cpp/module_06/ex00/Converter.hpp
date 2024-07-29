/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:00:40 by daraz             #+#    #+#             */
/*   Updated: 2024/07/25 15:36:27 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CONVERTER_HPP_
#define _CONVERTER_HPP_

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cctype>

class Converter {
	public:
		static void convert(const std::string &param);

	private:
		Converter();
		Converter(Converter const &src);
		~Converter();
		
		Converter &operator=(Converter const &src);
};

#endif
