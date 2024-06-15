/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:12:46 by daraz             #+#    #+#             */
/*   Updated: 2024/06/15 15:40:27 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB {

    private:
        std::string _name;
        Weapon*     _weapon;

    public:
        HumanB(std::string name);
        ~HumanB();

        void    attack(void) const;
        void    setWeapon(Weapon& weapon);
};