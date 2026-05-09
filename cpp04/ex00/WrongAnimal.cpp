/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:07:59 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/04 15:32:56 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#include <iostream>

// Constructors
WrongAnimal::WrongAnimal() {
	std::cout << "Default WrongAnimal constructor called\n";
};
WrongAnimal::WrongAnimal( const std::string& type ) : _type(type) {
	std::cout << "WrongAnimal type constructor called\n";
};
WrongAnimal::WrongAnimal( const WrongAnimal& other ) : _type(other._type) {
	std::cout << "WrongAnimal copy constructor called\n";
};
WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other ) {
	if (this != &other)
		this->_type = other._type;
	std::cout << "WrongAnimal copy assignment constructor called\n";
	return *this;
};
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called\n";
};
// Public Member Functions
const std::string	WrongAnimal::getType( void ) const {
	if (this->_type.empty())
		return "Type is undefined!";
	return this->_type;
};
void	WrongAnimal::makeSound() const {
	std::cout << "* wrongAnimal looks confused (no sound) *\n";
};
