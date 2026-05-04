/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:13:37 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/04 15:33:42 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	const WrongAnimal *wrongun = new WrongAnimal();
	const WrongAnimal *fish = new WrongCat();
	std::cout << wrongun->getType() << "\n";
	std::cout << fish->getType() << "\n";
	wrongun->makeSound();
	fish->makeSound();
	delete wrongun;
	delete fish;
	return 0;
};
