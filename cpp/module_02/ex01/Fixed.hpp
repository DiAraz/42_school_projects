/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:42:29 by daraz             #+#    #+#             */
/*   Updated: 2024/07/01 11:44:04 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed( const int n );
        Fixed( const float n );
        Fixed(const Fixed &src);
        ~Fixed();
        
        Fixed& operator=(const Fixed &src);
        int     getRawBits(void) const;
        void    setRawBits(int const rawBits);
        float   toFloat( void ) const;
        int     toInt( void ) const;

    private:
        int                 _value;
        static const int    _fractionalBits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & number);

#endif