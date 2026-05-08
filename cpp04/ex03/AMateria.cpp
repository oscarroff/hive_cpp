/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:08:30 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/08 14:34:02 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( const std::string& type ) : _type(type) {};
const std::string& AMateria::getType() const {
	return this->_type;
};
void	AMateria::use(ICharacter& target) {
	(void)target;
};
