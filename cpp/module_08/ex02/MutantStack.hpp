/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:01:16 by daraz             #+#    #+#             */
/*   Updated: 2024/09/09 12:06:23 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MUTANTSTACK_HPP_
#define _MUTANTSTACK_HPP_

#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <deque>

template< typename T, class Cont = std::deque<T> > 
class MutantStack : public std::stack<T, Cont>
{

    public:

        MutantStack() {};
        ~MutantStack() {};

        MutantStack(const MutantStack& src) {*this = src;}
        MutantStack&    operator=(const MutantStack& rhs) {
            if (this != &rhs) {
                std::stack< T, Cont >::operator=(rhs);
            }
            return *this;
        }

        typedef typename Cont::iterator    iterator;

        iterator    begin() {return this->c.begin();}
        iterator    end() {return this->c.end();}
};
#endif