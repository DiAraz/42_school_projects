/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:36:47 by daraz             #+#    #+#             */
/*   Updated: 2024/09/02 13:58:26 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
    Array<int> arr(10);
    Array<int> arr2(5);

    for (unsigned int i = 0; i < arr.size(); i++)
        arr[i] = i + i + 1;

    std::cout << "First Array:  " << arr << std::endl;

    arr2 = arr;

    std::cout << "Second Array: " << arr2 << std::endl;

    try {
        std::cout << "Correct index: " << arr[6] << std::endl;
        std::cout << "Not correct index: " << arr[15] << std::endl;
    } catch ( Array< int >::OutOfBoundsException& e ) {
        std::cout << e.what() << std::endl;
    }

    return (0);
}