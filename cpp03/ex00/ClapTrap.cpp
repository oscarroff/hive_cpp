/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:55:33 by thblack-          #+#    #+#             */
/*   Updated: 2026/04/29 13:51:35 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

// Constructors & Destructors
ClapTrap::ClapTrap()
: _hp(10), _energy(10), _damage(0) {
	std::cout << "Default constructor called\n";
};
ClapTrap::ClapTrap( const std::string name )
: _name(name), _hp(10), _energy(10), _damage(0) {
	std::cout << "Default constructor called\n";
};
ClapTrap::ClapTrap( const ClapTrap& other )
: _name(other._name), _hp(other._hp), _energy(other._energy), _damage(other._damage) {
	std::cout << "Copy constructor called\n";
};
ClapTrap&	ClapTrap::operator=( const ClapTrap& other ) {
	std::cout << "Copy assignment constructor called\n";
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_energy = other._energy;
		this->_damage = other._damage;
	}
	return *this;
};
ClapTrap::~ClapTrap() {
	std::cout << "Destructor called\n";
};

// Public Member Functions
void	ClapTrap::attack( const std::string& target ) {
	if (this->_hp < 1)
		std::cout << _name << " is out of hit points, attack failed!\n";
	else if (this->_energy < 1)
		std::cout << _name << " is out of energy, attack failed!\n";
	else
	{
		std::cout << _name << " attacks " << target << ", causing "
			<< _damage << " points of damage!\n";
		this->_energy--;
	}
};
void	ClapTrap::takeDamage( unsigned int amount ) {
	if (this->_hp < 1)
		std::cout << _name << "is already dead!\n";
	else
	{
		if (amount == 1)
			std::cout << _name << " is attacked, receiving 1 point of damage\n";
		std::cout << _name << " is attacked, receiving "
			<< amount << " points of damage!\n";
		this->_hp--;
	}
};
void	ClapTrap::beRepaired( unsigned int amount ) {
	if (this->_energy < 1)
		std::cout << _name << " is out of energy, repair failed!\n";
	else
	{
		if (amount == 1)
			std::cout << _name << " repairs itself, regaining 1 hit point\n";
		else
			std::cout << _name << " repairs itself, regaining " << amount
				<< " hit points\n";
		this->_energy--;
		this->_hp += amount;
	}
};
