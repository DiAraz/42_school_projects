/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:42:29 by daraz             #+#    #+#             */
/*   Updated: 2024/07/01 12:23:47 by daraz            ###   ########.fr       */
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
        
        bool	operator>( Fixed const & src ) const;
		bool	operator<( Fixed const & src ) const;
		bool	operator>=( Fixed const & src ) const;
		bool	operator<=( Fixed const & src ) const;
		bool	operator==( Fixed const & src ) const;
		bool	operator!=( Fixed const & src ) const;
        
        Fixed	operator+( Fixed const & src ) const;
		Fixed	operator-( Fixed const & src ) const;
		Fixed	operator*( Fixed const & src ) const;
		Fixed	operator/( Fixed const & src ) const;

        Fixed &	operator++( void );
		Fixed	operator++( int	);
		Fixed &	operator--( void );
		Fixed	operator--( int );

        static Fixed &			min( Fixed & src1, Fixed & src2 );
		static Fixed &			max( Fixed & src1, Fixed & src2 );
		static Fixed const &	min( Fixed const & src1, Fixed const & src2 );
		static Fixed const &	max( Fixed const & src1, Fixed const & src2 );
        
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