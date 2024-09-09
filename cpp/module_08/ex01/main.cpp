/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:20:11 by daraz             #+#    #+#             */
/*   Updated: 2024/09/04 16:21:12 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
    std::cout << "---- TEST FROM SUBJECT -----" << std::endl;

    Span sp = Span( 5 );

    sp.addNumber( 6 );
    sp.addNumber( 3 );
    sp.addNumber( 9 );
    sp.addNumber( 17 );
    sp.addNumber( 11 );
	//sp.addNumber( 6 );

    std::cout << sp.longestSpan() << std::endl;
    std::cout << sp.shortestSpan() << std::endl;

    std::cout << "\n---- TEST FOR 10 000 NUMBERS-----" << std::endl;

    try {
        std::list<int> list(10000);
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        std::list<int>::iterator begin = list.begin();
        std::list<int>::iterator end = list.end();
        std::generate(begin, end, std::rand);

        Span span(list.size());

        span.addNumber(begin, end);

        std::cout << span.longestSpan() << std::endl;
        std::cout << span.shortestSpan() << std::endl;
        
    } catch ( std::exception& e ) {
        std::cout << e.what() << std::endl; 
    }

    return 0;
}