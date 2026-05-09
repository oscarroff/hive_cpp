/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:37:39 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/08 15:14:26 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {};
Ice::Ice( const Ice& other) : AMateria("ice") { (void)other; };
// Copy assignement declared delete in header as usage makes no sense
Ice::~Ice() {};
void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
};
// We will use this crucial function for copying new instances.
Ice*	Ice::clone() const {
	return new Ice(*this);
}; 
const std::string&	Ice::getType() const {
	return this->_type;
};
