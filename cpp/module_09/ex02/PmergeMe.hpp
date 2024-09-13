/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:43:52 by daraz             #+#    #+#             */
/*   Updated: 2024/09/13 16:04:29 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <deque>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <set>

class PmergeMe {
	
	private:
		std::vector<int>	_containerVector;
		std::deque<int>		_containerDeque;
		const int			_size;

		void	_sortVector();
		void	_sortDeque();

    public:
		PmergeMe(std::vector<int> & input, int size);
		PmergeMe(PmergeMe const &src);
		~PmergeMe();

		PmergeMe &	operator=(PmergeMe const &rhs);
};