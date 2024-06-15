/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:00:00 by daraz             #+#    #+#             */
/*   Updated: 2024/06/15 15:16:54 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {

    private:
        std::string _type;

    public:
        Weapon(std::string type);
        ~Weapon();

        const std::string&  getType(void);
        void                setType(std::string newType);
};

#endif