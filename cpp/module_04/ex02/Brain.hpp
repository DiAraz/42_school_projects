/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:32:51 by daraz             #+#    #+#             */
/*   Updated: 2024/07/07 14:37:17 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{

    public:
        Brain(void);
        Brain(const Brain& src);
        Brain& operator=(const Brain& src);
         ~Brain(void);

    private:
        std::string _ideas[100];
    
};
 
#endif