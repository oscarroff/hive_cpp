/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:07:59 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/04 17:52:25 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>
#include <cstring>

// Constructors
Cat::Cat() : AAnimal(), _brain(new Brain) {
	this->setType("Cat");
	std::cout << "Default Cat constructor called\n";
};
Cat::Cat( const Cat& other ) : AAnimal(), _brain(new Brain) {
	this->setType("Cat");
	*this->_brain = *other._brain;
	std::cout << "Cat copy constructor called\n";
};
Cat& Cat::operator=( const Cat& other ) {
	if (this != &other)
	{
		this->setType("Cat");
		delete this->_brain;
		this->_brain = new Brain;
		*this->_brain = *other._brain;
	}
	std::cout << "Cat copy assignment constructor called\n";
	return *this;
};
Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat destructor called\n";
};
void	Cat::makeSound() const {
	std::cout << "* meow! *\n";
};
Brain*	Cat::mindMeld() const {
	return this->_brain;
};
