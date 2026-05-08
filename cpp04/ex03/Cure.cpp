/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:37:39 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/08 15:21:59 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {};
Cure::Cure( const Cure& other) : AMateria(other._type) {};
Cure&	Cure::operator=( const Cure& other ) {
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
};
Cure::~Cure() {};
void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
};
Cure*	Cure::clone() const {
	return new Cure(*this);
}; 
const std::string&	Cure::getType() const {
	return this->_type;
};
