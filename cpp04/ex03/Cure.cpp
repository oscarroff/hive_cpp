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
Cure::Cure( const Cure& other) : AMateria("cure") { (void)other; };
// Copy assignement declared delete in header as usage makes no sense
Cure::~Cure() {};
void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
};
// We will use this crucial function for copying new instances.
Cure*	Cure::clone() const {
	return new Cure(*this);
}; 
const std::string&	Cure::getType() const {
	return this->_type;
};
