/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:40:11 by daraz             #+#    #+#             */
/*   Updated: 2024/09/02 13:44:42 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>

template <typename T = int>
class Array
{
	public:
		class OutOfBoundsException : public std::exception {
			public:
				virtual char const *	what(void) const throw() {
					return ("Index out of bounds.");
				}
		};
		
		Array(void) : _array(NULL), _size(0) {}
		Array(unsigned int n) : _array(new T[n]), _size(n) {}
		Array(Array const & src) : _array(new T[src._size]), _size(src._size) {
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = src._array[i];
		}
		~Array(void) { delete [] _array; }

		Array &	operator=(Array const & src) {
			if (this == &src)
				return (*this);
			if (_size != src._size) {
				delete [] _array;
				_size = src._size;
				_array = new T[this->_size];
			}
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = src._array[i];
			return (*this);
		}

		T &	operator[](unsigned int index) {
			if (index >= _size)
				throw (OutOfBoundsException());
			return (_array[index]);
		}

		unsigned int	size(void) const {
			return (_size);
		}	

	private:
		T *				_array;
		unsigned int	_size;
};

template <typename T>
std::ostream &	operator<<(std::ostream &os, Array<T> &obj) {
    for (unsigned int i = 0; i < obj.size(); ++i) {
        os << "[" << obj[i] << "] ";
    }
    return (os);
}

#endif