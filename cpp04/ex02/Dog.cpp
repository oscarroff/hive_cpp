/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:07:59 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/04 17:54:27 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>
#include <cstring>

// Constructors
Dog::Dog() : Animal(), _brain(new Brain) {
	this->setType("Dog");
	std::cout << "Default Dog constructor called\n";
};
Dog::Dog( const Dog& other ) : Animal(), _brain(new Brain) {
	this->setType("Dog");
	*this->_brain = *other._brain;
	std::cout << "Dog copy constructor called\n";
};
Dog& Dog::operator=( const Dog& other ) {
	if (this != &other)
	{
		this->setType(other.getType());
		delete this->_brain;
		this->_brain = new Brain;
		*this->_brain = *other._brain;
	}
	std::cout << "Dog copy assignment constructor called\n";
	return *this;
};
Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog destructor called\n";
};
void	Dog::makeSound() const {
	std::cout << "Meow\n";
};
Brain*	Dog::mindMeld() const {
	return this->_brain;
};
