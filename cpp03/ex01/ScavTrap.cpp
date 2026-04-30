/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:55:33 by thblack-          #+#    #+#             */
/*   Updated: 2026/04/29 14:31:54 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

// Constructors & Destructors
ScavTrap::ScavTrap( const std::string name )
: _name(name), _hp(10), _energy(10), _damage(0) {
	std::cout << "Scavvy default constructor called\n";
};
ScavTrap::ScavTrap( const ScavTrap& other )
: _name(other._name), _hp(other._hp), _energy(other._energy), _damage(other._damage) {
	std::cout << "Scavvy copy constructor called\n";
};
ScavTrap&	ScavTrap::operator=( const ScavTrap& other ) {
	std::cout << "Scavvy copy assignment constructor called\n";
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_energy = other._energy;
		this->_damage = other._damage;
	}
	return *this;
};
ScavTrap::~ScavTrap() {
	std::cout << "Scavvy destructor called\n";
};

// Public Member Functions
void	ScavTrap::guardGate() {
	std::cout << _name << "is now in gate keeper mode!\n";
};
