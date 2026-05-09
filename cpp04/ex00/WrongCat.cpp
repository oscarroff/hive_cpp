/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:07:59 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/04 15:33:28 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include <iostream>

// Constructors
WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "Default WrongCat constructor called\n";
};
WrongCat::WrongCat( const WrongCat& other ) : WrongAnimal(other._type) {
	std::cout << "WrongCat copy constructor called\n";
};
WrongCat& WrongCat::operator=( const WrongCat& other ) {
	if (this != &other)
		this->_type = other._type;
	std::cout << "WrongCat copy assignment constructor called\n";
	return *this;
};
WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called\n";
};
void	WrongCat::makeSound() const {
	std::cout << "* blurp! *\n";
};
