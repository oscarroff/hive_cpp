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

#include "AAnimal.hpp"

#include <iostream>

// Public Member Functions
const std::string	AAnimal::getType( void ) const {
	if (this->_type.empty())
		return "Type is undefined!";
	return this->_type;
};
void	AAnimal::setType( const std::string& type ) {
	this->_type = type;
};
void	AAnimal::makeSound() const {
	std::cout << "Animal tries to make sound but can't decide what\n";
};
