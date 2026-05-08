/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:58:09 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/08 14:09:46 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource() {};
MateriaSource::MateriaSource( const MateriaSource& other) {
	for (int i = 0; i < 4; i++)
		this->_skills[i] = other._skills[i] ? other._skills[i]->clone() : nullptr;
};
MateriaSource&	MateriaSource::operator=( const MateriaSource& other ) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			delete this->_skills[i];
			this->_skills[i] = other._skills[i] ? other._skills[i]->clone() : nullptr;
		}
	}
	return *this;
};
MateriaSource::~MateriaSource() {};
void		MateriaSource::learnMateria(AMateria *m) {
	for (int size = 0; this->_skills[size]; size++) {
		if (size < 4) {
			this->_skills[size] = m->clone();
		}
	}
}
AMateria*	MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; this->_skills[i]; i++)
		if (this->_skills[i]->getType() == type) {
			if (type == "ice") {
				AMateria* ice = new Ice();
				return ice;
			}
		}
	return 0;
}
