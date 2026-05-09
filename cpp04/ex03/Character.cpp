/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:37:39 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/08 15:49:09 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include <cstring>

// Constructors and destructors
Character::Character( const std::string& name ) : _name(name) {};
// Copy name and copy Materias if they exist using clone()
Character::Character( const Character& other) : _name(other._name) {
	for (int i = 0; i < 4; i++)
		this->_items[i] = other._items[i] ? other._items[i]->clone() : nullptr;
};
// Copy name, delete preexisting Materias if they exist then copy Materias if
// they exist using clone()
Character&	Character::operator=( const Character& other ) {
	if (this != &other) {
		this->_name = other._name;
		for (int i = 0; i < 4; i++) {
			if (this->_items[i])
				delete this->_items[i];
			this->_items[i] = other._items[i] ? other._items[i]->clone() : nullptr;
		}
	}
	return *this;
};
// Delete any Materias
Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (this->_items[i] != nullptr) 
			delete this->_items[i];
};

// Public member functions
const std::string& Character::getName() const {
	return this->_name;
};
// Equip a Materia if there is space. Safer behaviour might be to delete a Materia
// which doesn't fit. But this is disallowed by the subject,: "Nothing should
// happen." This goes into questions of ownership.
void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++)
		if (!this->_items[i]) {
			this->_items[i] = m;
			return ;
		}
};
// Set slot to null if it is within the range of the inventory. No deletion, thus
// Materias are potentially left hanging and must be deleted separately.
void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return ;
	this->_items[idx] = nullptr;
};
// Use a Materia if it exists.
void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3)
		return ;
	if (this->_items[idx])
		this->_items[idx]->use(target);
};
