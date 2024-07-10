/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:55:07 by daraz             #+#    #+#             */
/*   Updated: 2024/07/06 14:12:30 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete  meta;
    delete  j;
    delete  i;

    std::cout << std::endl << std::endl;

    const WrongAnimal *wrongMeta = new WrongAnimal();
    const WrongAnimal *wrongCat = new WrongCat();

    std::cout << wrongMeta->getType() << std::endl;
    std::cout << wrongCat->getType() << std::endl;
    wrongMeta->makeSound();
    wrongCat->makeSound();

    delete  wrongMeta;
    delete  wrongCat;

    return 0;
}