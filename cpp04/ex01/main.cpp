/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:13:37 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/04 17:19:54 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main( void ) {
	Animal*	herd[10];
	for (size_t i = 0; i < 5; i++)
		herd[i] = new Cat();
	for (size_t i = 5; i < 10; i++)
		herd[i] = new Dog();
	// We need to use casting to access the Cat (or Dog) objects.
	// dynamic_cast would also be an option. But I know that those are cats so
	// I can use statc.
	// If I wasn't following the subject so strictly I would implement the
	// eureka() and mindPalace() members in the base Animal class which would
	// negate the need for casting.
	std::cout << "\n";
	Cat* cat1 = static_cast<Cat*>(herd[0]);
	Cat* cat2 = static_cast<Cat*>(herd[1]);
	if (cat1) {
		cat1->makeSound();
		cat1->mindMeld()->eureka("I like fish\n");
		cat1->mindMeld()->eureka("Humans are stoopid\n");
		cat1->mindMeld()->eureka("I will claw your face clean off\n");
		cat1->mindMeld()->eureka("I love you\n");
		std::cout << cat1->mindMeld()->mindPalace(0);
		std::cout << cat1->mindMeld()->mindPalace(1);
		std::cout << cat1->mindMeld()->mindPalace(2);
		std::cout << cat1->mindMeld()->mindPalace(3);
		std::cout << cat1->mindMeld()->mindPalace(4);
		std::cout << cat1->mindMeld()->mindPalace(100);
		std::cout << cat1->mindMeld() << "\n";
	}
	std::cout << "\n";
	if (cat1 && cat2) {
		*cat2 = *cat1;
		std::cout << "\n";
		cat2->makeSound();
		std::cout << cat2->mindMeld()->mindPalace(0);
		std::cout << cat2->mindMeld()->mindPalace(1);
		std::cout << cat2->mindMeld()->mindPalace(2);
		std::cout << cat2->mindMeld()->mindPalace(3);
		std::cout << cat2->mindMeld()->mindPalace(4);
		std::cout << cat2->mindMeld()->mindPalace(100);
		std::cout << cat2->mindMeld() << "\n";
	}
	std::cout << "\n";
	for (size_t i = 0; i < 10; i++)
		delete herd[i];
	return (0);
};
