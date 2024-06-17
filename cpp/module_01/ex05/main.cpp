/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:54:01 by daraz             #+#    #+#             */
/*   Updated: 2024/06/17 13:44:59 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(void) {

    std::string input;
    Harl        harl;

    while (input.compare("EXIT")) {
        std::cout << std::endl << "Enter a level (DEBUG, INFO, WARNING, ERROR): ";
        std::cin >> input;
        harl.complain(input);
    }

    return 0;
}