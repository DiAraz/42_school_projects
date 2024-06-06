/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:33:41 by daraz             #+#    #+#             */
/*   Updated: 2024/06/06 14:29:59 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.class.hpp"
#include <limits>

int main() {
    
    std::string input;
    PhoneBook phoneBook;
    
    std::cout << std::endl << "Welcome to your PhoneBook!" << std::endl;
    std::cout << std::endl << "Select next action:" << std::endl << std::endl
                             << "ADD to add a contact" << std::endl
                             << "SEARCH to search a contact" << std::endl
                             << "EXIT to exit" << std::endl << std::endl;

    std::getline(std::cin, input);
    std::cout << std::endl;
        
    while (1) {
        
        if (input == "EXIT")
            break;
        else if (input == "ADD") {
            phoneBook.addContact();
            std::cout << "What is your next action?" << std::endl << std::endl;
        }
        else if (input =="SEARCH") {
            phoneBook.printAllContacts();
            phoneBook.search();
            std::cout << "What is your next action?" << std::endl << std::endl;
        }
        else {
            std::cout << "Provide a valid action" << std::endl;
        }
        
        std::getline(std::cin, input);
        std::cout << std::endl;
    }

    std::cout << std::endl << "Thank you for using your PhoneBook and have a great day!" << std::endl << std::endl;
    
    return 0;
}