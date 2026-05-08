/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:37:39 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/07 14:47:55 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include <iostream>

Ice::Ice() : AMateria("Ice") {};
// Ice::Ice( const Ice& other) : AMateria(other._type) {};
// Ice&	Ice::operator=( const Ice& other ) {
// 	if (this != &other) {
// 		AMateria::operator=(other);
// 	}
// 	return *this;
// };
void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at <name> *\n";
	(void)target;
	// std::cout << "* shoots an ice bolt at " << target << " *\n";
};
Ice*	Ice::clone() const {
	return new Ice(*this);
}; 
