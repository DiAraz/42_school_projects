/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:33:35 by daraz             #+#    #+#             */
/*   Updated: 2024/06/05 15:48:12 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <limits>

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

int     PhoneBook::_getInput() const {
    int     userInput = -1;
    bool    valid = false;
    do
    {
        std::cout << "Enter the contact index: " << std::flush;
        std::cin >> userInput;
        if (std::cin.good() && (userInput >= 0 && userInput < 8)) {
            valid = true;
        } else {
            std::cin.clear();
            //After an invalid input, the input buffer might still contain unwanted characters (like leftover characters from a previous input).
            //This line ensures that the entire line of input is discarded, preventing those characters from interfering with subsequent input operations.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Provide a valid index." << std::endl;
        }
    } while (!valid);
    return (userInput);
}

void    PhoneBook::search(void) const {
    int i = this->_getInput();
    this->_contacts[i].printFullContact(i);
}