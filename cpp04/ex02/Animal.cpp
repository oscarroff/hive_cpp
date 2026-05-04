/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:07:59 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/04 17:55:13 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

// Public Member Functions
const std::string	Animal::getType( void ) const {
	if (this->_type.empty())
		return "Type is undefined!";
	return this->_type;
};
void	Animal::setType( const std::string& type ) {
	this->_type = type;
};
void	Animal::makeSound() const {
	std::cout << "Animal tries to make sound but can't decide what\n";
};
