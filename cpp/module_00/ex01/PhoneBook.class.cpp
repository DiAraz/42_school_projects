/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:33:35 by daraz             #+#    #+#             */
/*   Updated: 2024/06/11 14:38:29 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <limits>
#include <sstream>

PhoneBook::PhoneBook()
{
    
}

PhoneBook::~PhoneBook()
{
    
}

void    PhoneBook::addContact(void) {
    static int  i; //in C++ static is initialized to 0
    this->_contacts[i % 8].setContact();
    this->_contacts[i % 8].setIndex(i % 8);
    i++;
}

void    PhoneBook::printAllContacts(void) const {
    std::cout << "------------- YOUR CONTACTS -------------" << std::endl;
    
    int i = 0;

    while (i < 8) {
        this->_contacts[i].getContactsOverview(i);
        i++;
    }

    std::cout << std::endl;
}

int PhoneBook::_getInput() const {
    int userInput = -1;
    bool valid = false;
    std::string input;

    do {
        std::cout << "Enter the contact index: " << std::flush;
        std::getline(std::cin, input);

        if (!input.empty()) {
            std::stringstream ss(input);
            if (ss >> userInput && ss.eof() && userInput >= 0 && userInput < 8) {
                valid = true;
            } else {
                std::cout << "Provide a valid index." << std::endl;
            }
        } else {
            std::cout << "Input cannot be empty." << std::endl;
        }
        
    } while (!valid);

    return userInput;
}

void    PhoneBook::search(void) const {
    int i = this->_getInput();
    this->_contacts[i].printFullContact(i);
}