/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:52:29 by daraz             #+#    #+#             */
/*   Updated: 2024/07/07 14:45:10 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog(void);
        Dog(const Dog& src);
        Dog& operator=(const Dog& src);
        ~Dog(void);

        void   makeSound(void) const;

    private:
        Brain   *_brain;

};

#endif