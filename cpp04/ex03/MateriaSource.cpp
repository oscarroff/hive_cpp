/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:58:09 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/08 15:20:05 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

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
MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->_skills[i])
			delete this->_skills[i] ;
	}
};
void		MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!this->_skills[i]) {
			this->_skills[i] = m;
			return ;
		}
	}
	delete m;
}
AMateria*	MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; this->_skills[i]; i++)
		if (this->_skills[i]->getType() == type)
				return this->_skills[i]->clone();
	return 0;
}
