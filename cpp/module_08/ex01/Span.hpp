/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:19:50 by daraz             #+#    #+#             */
/*   Updated: 2024/09/04 10:43:53 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SPAN_HPP_
#define _SPAN_HPP_

#include <list>
#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <climits>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <unistd.h>

class Span
{

    public:
        Span(unsigned int);
        Span(const Span&);
        ~Span();
        Span& operator=(const Span&);

        
        void                addNumber(int);
        void                addNumber(std::list<int>::const_iterator, std::list<int>::const_iterator);
        unsigned int        longestSpan() const;
        unsigned int        shortestSpan() const;
        
    private:
    std::list<int>  _list;
    unsigned int    _n;

    Span( void );
};

#endif