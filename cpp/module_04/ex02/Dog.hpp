/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:52:29 by daraz             #+#    #+#             */
/*   Updated: 2024/07/10 10:31:17 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"

class Dog : public AAnimal
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