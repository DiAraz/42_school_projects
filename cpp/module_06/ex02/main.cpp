/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:51:10 by daraz             #+#    #+#             */
/*   Updated: 2024/07/29 13:34:49 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdexcept>
#include <ctime>
#include <cstdlib>

class Base { public: virtual ~Base() {} };
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *	generate(void)
{
	int	rnb = std::rand() % 3;

	switch (rnb)
	{
		case 0:
			std::cout << "New A created" << std::endl;
			return (new A);
		case 1:
			std::cout << "New B created" << std::endl;
			return (new B);
		case 2:
			std::cout << "New C created" << std::endl;
			return (new C);
	}
	return (NULL);
}

void    identify( Base* p ) {
    if ( dynamic_cast< A* >( p ) )
        std::cout << "A type pointer" << std::endl;
    else if ( dynamic_cast< B* >( p ) )
        std::cout << "B type pointer" << std::endl;
    else if ( dynamic_cast< C* >( p ) )
        std::cout << "C type pointer" << std::endl;
    else
        std::cout << "unknown" << std::endl;
}

void    identify( Base& p ) {
    try {
        A& a = dynamic_cast< A& >( p );
        std::cout << "A type pointer" << std::endl;
        (void)a;
    } catch(const std::exception& e) {}
    try {
        B& b = dynamic_cast< B& >( p );
        std::cout << "B type pointer" << std::endl;
        (void)b;
    } catch( const std::exception& e ) {}
    try {
        C& c = dynamic_cast< C& >( p );
        std::cout << "C type pointer" << std::endl;
        (void)c;
    } catch( const std::exception& e ) {}
}

int main() {
    for (int i = 0; i < 5; ++i) {
        Base* ptr = generate();

        identify(ptr);
        identify(*ptr);

        delete ptr;

        std::cout << std::endl;
    }

    return 0;
}