/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:51:18 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/25 16:46:39 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
# include <iostream>

HumanB::HumanB( std::string name ) : _name(name), _weapon(nullptr) {};
HumanB::~HumanB() {};

void	HumanB::attack( void )
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their "
			<< this->_weapon->getType() << "\n";
	else
		std::cout << this->_name << " attacks with their lethal sense of humour\n";
}
void	HumanB::setWeapon( Weapon& weapon )
{
	this->_weapon = &weapon;
}
