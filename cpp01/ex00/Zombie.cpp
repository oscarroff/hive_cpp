/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:51:01 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/19 18:25:44 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name )
{
	this->_name = name;
}
Zombie::~Zombie( void )
{
	std::cout << this->_name << ": was destroyed\n";
}
void	Zombie::announce( void )
{
	std::cout << getName() << ": BraiiiiiiinnnzzzZ...\n";
}
std::string	Zombie::getName( void )
{
	return this->_name ;
}
