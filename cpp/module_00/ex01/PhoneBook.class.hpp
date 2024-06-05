/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:34:52 by daraz             #+#    #+#             */
/*   Updated: 2024/06/05 15:47:20 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"

class PhoneBook
{
private:
    Contact     _contacts[8];
    int         _getInput(void) const;
    
public:
    PhoneBook();
    ~PhoneBook();
    void    addContact(void);
    void    printAllContacts(void) const;
    void    search(void) const;
};

#endif