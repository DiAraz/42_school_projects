/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:55:07 by daraz             #+#    #+#             */
/*   Updated: 2024/07/10 10:41:21 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongCat.hpp"

int main( void )
{
    /* const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;//should not create a leak
    delete i; */

    Dog dog; //testing the deep copy
    {
        Dog copy = dog;
    }

    /* const Animal* animals[6] = { new Cat(), new Dog(), new Dog(), new Cat(), new Cat(), new Dog() };
    for ( int i = 0; i < 6; i++ ) {
        delete animals[i];
    } */

    /* AAnimal * animal = new AAnimal(); //should not work, abstract class
 	animal.makeSound();
 	delete animal; */


    return 0;
}