/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:47:29 by daraz             #+#    #+#             */
/*   Updated: 2024/07/10 10:31:23 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"

class Cat : public AAnimal
{
    public:
        Cat(void);
        Cat(const Cat& src);
        Cat& operator=(const Cat& src);
        ~Cat(void);

        void   makeSound(void) const;
        
    private:
        Brain   *_brain;
};

#endif