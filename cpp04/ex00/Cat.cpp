/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:07:59 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/04 15:29:53 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

// Constructors
Cat::Cat() : Animal("Cat") {
	std::cout << "Default Cat constructor called\n";
};
Cat::Cat( const Cat& other ) : Animal(other._type) {
	std::cout << "Cat copy constructor called\n";
};
Cat& Cat::operator=( const Cat& other ) {
	if (this != &other)
		this->_type = other._type;
	std::cout << "Cat copy assignment constructor called\n";
	return *this;
};
Cat::~Cat() {
	std::cout << "Cat destructor called\n";
};
void	Cat::makeSound() const {
	std::cout << "* meow! *\n";
};
