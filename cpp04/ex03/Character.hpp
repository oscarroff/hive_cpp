/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:03:13 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/07 15:01:11 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

// Forward declation of a class
class	AMateria;

class	Character : ICharacter {
private:
	std::string	_name;
	// Array of Materia slots, this syntax initialises all pointers to NULL
	// at declaration
	AMateria*	_items[4] = {};
	// Construction controlled in protected to prevent direct instantiation
	// without name
public:
	// Constructors & Desctructors
	Character();
	Character( const std::string& name );
	Character( const Character& other );
	Character&	operator=( const Character& other );
	// Virtual destructor is essential if base class is to be used polymorphically
	virtual ~Character();

	// Public member functions
	std::string const &getName() const override;
	void equip(AMateria *m) override;
	void unequip(int idx) override;
	void use(int idx, Character &target) override;
};
