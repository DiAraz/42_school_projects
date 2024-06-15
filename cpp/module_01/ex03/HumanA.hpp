/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:11:06 by daraz             #+#    #+#             */
/*   Updated: 2024/06/15 15:30:14 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA {
    
    private:
        std::string _name;
        Weapon&     _weapon;

    public:
        HumanA(std::string name, Weapon& weapon);
        ~HumanA();

        void    attack(void) const;
};