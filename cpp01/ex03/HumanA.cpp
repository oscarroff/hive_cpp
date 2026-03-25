/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:45:54 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/25 16:46:53 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
# include <iostream>

// Construtor taking its weapon as a reference
// Weapon needs to initialize weapon in order to work (code after thhe single
// colon ':'
HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon) {};
HumanA::~HumanA() {};

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their "
		<< this->_weapon.getType() << "\n";
}
