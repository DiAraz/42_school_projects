/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:34:57 by daraz             #+#    #+#             */
/*   Updated: 2024/06/05 15:21:22 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

# include <string>
#include <iostream>
#include <iomanip>

class Contact {
  
  private:
          int         _index;
          std::string _firstName;
          std::string _lastName;
          std::string _nickName;
          std::string _phoneNumber;
          std::string _darkSecret;

          std::string parseUserInput(std::string str) const;
          std::string _printContact(std::string str) const;

  public:
         Contact(void);
         ~Contact(void);


         void    setIndex(int i);
         void    setContact(void);
         void    getContactsOverview(int index) const;
         void    printFullContact(int index) const;
};

#endif