/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:42:09 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/25 14:45:48 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type )
{
	this->_type = type;
}
Weapon::~Weapon( void ) {};

const std::string	Weapon::getType( void )
{
	return this->_type;
}
void	Weapon::setType( std::string type )
{
	this->_type = type;
}
