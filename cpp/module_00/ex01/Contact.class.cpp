/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:34:24 by daraz             #+#    #+#             */
/*   Updated: 2024/06/05 16:46:43 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include <limits>


Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setIndex(int i) {
    this->_index = i;
}

std::string Contact::parseUserInput(std::string str) const {
    std::string input = "";
    bool        correctInput = false;
    do
    {
        std::cout << str << std::flush;
        std::getline(std::cin, input);
        if (std::cin.good() && !input.empty())
            correctInput = true;
        else {
            std::cin.clear();
            std::cout << "Invalid input!" << std::endl;
        }
    } while (!correctInput);
    return (input);
}

void    Contact::setContact(void) {
    //std::cin.ignore();
    this->_firstName = this->parseUserInput("Enter first name: ");
    this->_lastName = this->parseUserInput("Enter last name: ");
    this->_nickName = this->parseUserInput("Enter nickname: ");
    this->_phoneNumber = this->parseUserInput("Enter phone number: ");
    this->_darkSecret = this->parseUserInput("Enter darkest secret: ");
    std::cout << std::endl;
}

void    Contact::getContactsOverview(int index) const {
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickName.empty())
        return ;
    std::cout << "|" << std::setw(10) << index << std::flush;
    std::cout << "|" << std::setw(10) << this->_printContact(this->_firstName) << std::flush;
    std::cout << "|" << std::setw(10) << this->_printContact(this->_lastName) << std::flush;
    std::cout << "|" << std::setw(10) << this->_printContact(this->_nickName) << std::flush;
    std::cout << "|" << std::endl;
}

std::string Contact::_printContact(std::string str) const {
    std::string result;
    if (str.size() > 10) {
        result = str.substr(0, 9);
        result += ".";
    } else {
        result = str;
    }
    return result;
}

void    Contact::printFullContact(int index) const {
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickName.empty() || this-> _phoneNumber.empty()
        || this->_darkSecret.empty()) {
        std::cout << "No record at index [" << index << "]. ADD a contact and SEARCH again." << std::endl <<std::endl;
        return ;
    }
    std::cout << std::endl;
    std::cout << "------ CONTACT " << index << " ------" << std::endl;
    std::cout << "First Name:\t" << this->_firstName << std::endl;
    std::cout << "Last Name:\t" << this->_lastName << std::endl;
    std::cout << "Nickname:\t" << this->_nickName << std::endl;
    std::cout << "Phone Number:\t" << this->_phoneNumber << std::endl;
    std::cout << "Darkest Secret:\t" << this->_darkSecret << std::endl;
    std::cout << std::endl;
}