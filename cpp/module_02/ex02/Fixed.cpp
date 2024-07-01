/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:42:33 by daraz             #+#    #+#             */
/*   Updated: 2024/07/01 12:38:40 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

/* CONSTRUCTORS */

Fixed::Fixed() {
    this->_value = 0;
}

Fixed::Fixed(const Fixed &src) {
    *this = src;
}

/*This operation effectively multiplies n by 2 on _fractionalBits. For example, if _fractionalBits is 8, then n << _fractionalBits is equivalent to n * 256.*/
Fixed::Fixed( const int n ) : _value( n << _fractionalBits ) {}

Fixed::Fixed( const float n ) : _value( roundf( n * ( 1 << _fractionalBits ) ) ) {}

Fixed::~Fixed() {}

/* OPERATORS OVERLOADS */

Fixed& Fixed::operator=(const Fixed &src) {
    if (this != &src)
        this->_value = src.getRawBits();
    return *this;
}

bool    Fixed::operator>( const Fixed &src ) const {
    return this->getRawBits() > src.getRawBits();
}

bool    Fixed::operator<( const Fixed &src ) const {
    return this->getRawBits() < src.getRawBits();
}

bool    Fixed::operator>=( const Fixed &src ) const {
    return this->getRawBits() >= src.getRawBits();
}

bool   Fixed::operator<=( const Fixed &src ) const {
    return this->getRawBits() <= src.getRawBits();
}

bool  Fixed::operator==( const Fixed &src ) const {
    return this->getRawBits() == src.getRawBits();
}

bool    Fixed::operator!=( const Fixed &src ) const {
    return this->getRawBits() != src.getRawBits();
}

Fixed   Fixed::operator+( const Fixed &src ) const {
    return Fixed( this->toFloat() + src.toFloat() );
}

Fixed   Fixed::operator-( const Fixed &src ) const {
    return Fixed( this->toFloat() - src.toFloat() );
}

Fixed   Fixed::operator*( const Fixed &src ) const {
    return Fixed( this->toFloat() * src.toFloat() );
}

Fixed   Fixed::operator/( const Fixed &src ) const {
    return Fixed( this->toFloat() / src.toFloat() );
}

Fixed&   Fixed::operator++( void ) {
    ++this->_value;
    return *this;
}

Fixed   Fixed::operator++( int ) {
    Fixed tmp( *this );
    tmp._value = this->_value++;
    return tmp;
}

Fixed& Fixed::operator--( void ) {
    --this->_value;
    return *this;
}

Fixed Fixed::operator--( int ) {
    Fixed tmp( *this );
    tmp._value = this->_value--;
    return tmp;
}

/* GET & SET */

int Fixed::getRawBits(void) const {
    return this->_value;
}

void    Fixed::setRawBits(int const rawBits) {
    this->_value = rawBits;
}

/* PUBLIC FUNCTIONS */

int		Fixed::toInt( void ) const
{
	return ( this->_value >> Fixed::_fractionalBits );	
}

float	Fixed::toFloat( void ) const
{
	return ( (float)this->_value / (1 << _fractionalBits) );
}

std::ostream& operator<<(std::ostream& o, const Fixed& number)
{
	o << number.toFloat();
	return (o);
}

/* MIN & MAX */

Fixed &	Fixed::min( Fixed & src1, Fixed & src2 )
{
	if ( src1 <= src2 )
		return ( src1 );
	return ( src2 );
}

Fixed const &	Fixed::min( Fixed const & src1, Fixed const & src2 )
{
	if ( src1 <= src2 )
		return ( src1 );
	return ( src2 );
}

Fixed &	Fixed::max( Fixed & src1, Fixed & src2 )
{
	if ( src1 >= src2 )
		return ( src1 );
	return ( src2 );
}

Fixed const &	Fixed::max( Fixed const & src1, Fixed const & src2 )
{
	if ( src1 >= src2 )
		return ( src1 );
	return ( src2 );
}