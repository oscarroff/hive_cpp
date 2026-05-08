/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:08:30 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/06 13:43:40 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( const std::string& type ) : _type(type) {};
// Returns the materia type
const std::string& AMateria::getType() const {
	return this->_type;
};
// void use(ICharacter& target) {};
