/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:37:39 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/08 15:44:11 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include <cstring>

// Constructors and destructors
Character::Character( const std::string& name ) : _name(name) {};
Character::Character( const Character& other) : _name(other._name) {
	for (int i = 0; i < 4; i++)
	{
		if (this->_items[i])
			delete this->_items[i];
		this->_items[i] = other._items[i] ? other._items[i]->clone() : nullptr;
	}
};
Character&	Character::operator=( const Character& other ) {
	if (this != &other) {
		this->_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_items[i])
				delete this->_items[i];
			this->_items[i] = other._items[i] ? other._items[i]->clone() : nullptr;
		}
	}
	return *this;
};
#include <iostream>
Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (this->_items[i] != nullptr) {
			std::cout << "delete " << i << "\n";
			delete this->_items[i];
		}
};

// Public member functions
const std::string& Character::getName() const {
	return this->_name;
};
void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++)
		if (!this->_items[i]) {
			this->_items[i] = m;
			return ;
		}
	delete m;
};
void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return ;
	int	size = 0;
	while (this->_items[size])
		size++;
	std::cout << size << "\n";
	if (idx == size - 1)
		this->_items[idx] = nullptr;
	if (idx < size - 1)
	{
		for (int i = idx; i < size - 1; i++)
			this->_items[i] = this->_items[i + 1];
		this->_items[size - 1] = nullptr;
	}
};
void Character::use(int idx, ICharacter &target) {
	if (this->_items[idx])
		this->_items[idx]->use(target);
};
