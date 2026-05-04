/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:07:59 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/04 15:31:26 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

// Constructors
Dog::Dog() : Animal("Dog") {
	std::cout << "Default Dog constructor called\n";
};
Dog::Dog( const Dog& other ) : Animal(other._type) {
	std::cout << "Dog copy constructor called\n";
};
Dog& Dog::operator=( const Dog& other ) {
	if (this != &other)
		this->_type = other._type;
	std::cout << "Dog copy assignment constructor called\n";
	return *this;
};
Dog::~Dog() {
	std::cout << "Dog destructor called\n";
};
void	Dog::makeSound() const {
	std::cout << "Woof\n";
};
