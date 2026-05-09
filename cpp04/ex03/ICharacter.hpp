/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:03:13 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/08 14:13:25 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include <string>

// Forward declation of a class
class	AMateria;

class ICharacter
{
public:
	// Curly brackets {} denote an empty function body meaning the virtual
	// destructor does nothing except default behaviour. This ensures that
	// derived concrete class destructors are called.
	virtual ~ICharacter() {};
	virtual std::string const &getName() const = 0;
	virtual void equip(AMateria *m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter &target) = 0;
};
