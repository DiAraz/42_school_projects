/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:20:16 by daraz             #+#    #+#             */
/*   Updated: 2024/09/04 10:58:35 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::~Span() {}

Span::Span(const Span& src) {
    *this = src;
}

Span& Span::operator=(Span const &rhs) {
    if ( this != &rhs ) {
        this->_n = rhs._n;
        this->_list = rhs._list;
    }
    return *this;
}


void Span::addNumber(int n) {
    if ( _list.size() >= _n )
        throw std::out_of_range("Can't add more numbers, list is full.");
    _list.push_back(n);
}

void Span::addNumber(std::list<int>::const_iterator itBegin, std::list<int>::const_iterator itEnd) {
    if (_list.size() >= _n)
        throw std::out_of_range("Can't add more numbers, list is full.");
    _list.insert(_list.end(), itBegin, itEnd);
}

unsigned int    Span::longestSpan() const {
    if (_list.size() < 2)
        throw std::out_of_range("Not enough numbers to calculate span.");
    std::list<int>::const_iterator it_begin = _list.begin();
    std::list<int>::const_iterator it_end = _list.end();

    unsigned int max_element = *std::max_element(it_begin, it_end);
    unsigned int min_element = *std::min_element(it_begin, it_end);

    return max_element - min_element;
}

unsigned int Span::shortestSpan() const {
    if (_list.size() < 2)
        throw std::out_of_range("Not enough numbers to calculate span.");
    unsigned int  min = Span::longestSpan();

    std::list<int>::const_iterator it1;
    std::list<int>::const_iterator it2;

    for (it1 = _list.begin(); it1 != _list.end(); ++it1) {
        for (it2 = _list.begin(); it2 != _list.end(); ++it2) {
            if (it1 == it2) continue;
            int diff = std::abs(*it2 - *it1);
            if (diff < static_cast<int>(min)) {
                min = diff;
            }
        }
    }
    return min;
}