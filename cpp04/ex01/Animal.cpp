/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:07:59 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/04 15:28:53 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

// Constructors
Animal::Animal() {
	std::cout << "Default Animal constructor called\n";
};
Animal::Animal( const std::string& type ) : _type(type) {
	std::cout << "Animal type constructor called\n";
};
Animal::Animal( const Animal& other ) : _type(other._type) {
	std::cout << "Animal copy constructor called\n";
};
Animal& Animal::operator=( const Animal& other ) {
	if (this != &other)
		this->_type = other._type;
	std::cout << "Animal copy assignment constructor called\n";
	return *this;
};
Animal::~Animal() {
	std::cout << "Animal destructor called\n";
};
// Public Member Functions
const std::string	Animal::getType( void ) const {
	if (this->_type.empty())
		return "Type is undefined!";
	return this->_type;
};
void	Animal::makeSound() const {
	std::cout << "Animal tries to make sound but can't decide what\n";
};
