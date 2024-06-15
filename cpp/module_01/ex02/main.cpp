/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:04:41 by daraz             #+#    #+#             */
/*   Updated: 2024/06/15 14:22:03 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main( void )
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Address of string:    " << &str << "    Value of string:    " << str << std::endl;
    std::cout << "Address of pointer:   "<< stringPTR << "    Value of pointer:   " << *stringPTR << std::endl;
    std::cout << "Address of reference: "<< &stringREF << "    Value of reference: " << stringREF << std::endl;

    return 0;
}