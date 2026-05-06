/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:55:33 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/03 13:21:50 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

// Constructors & Destructors
DiamondTrap::DiamondTrap()
: ScavTrap(), FragTrap() {
	this->setHp(100);
	this->setEnergy(50);
	this->setDamage(30);
	std::cout << "Sparkly default constructor called\n";
};
// Name constructor explicity lists ClapTrap name in initializer list
// Without ClapTrap(name) the compiler may default to the default constructor
// ClapTrap()
DiamondTrap::DiamondTrap( const std::string name )
: ClapTrap(name), ScavTrap(name), FragTrap(name) {
	this->_name = name;
	ClapTrap::setName(name + "_clap_name");
	this->setHp(100);
	this->setEnergy(50);
	this->setDamage(30);
	std::cout << "Sparkly named constructor called\n";
};
// Copy constructor explicity lists ClapTrap name in initializer list
// Without ClapTrap(other) the compiler may default to the default constructor
DiamondTrap::DiamondTrap( const DiamondTrap& other )
: ClapTrap(other), ScavTrap(other), FragTrap(other) {
	this->_name = other._name;
	ClapTrap::setName(other.getName());
	this->setHp(FragTrap::getHp());
	this->setEnergy(ScavTrap::getEnergy());
	this->setDamage(FragTrap::getDamage());
	std::cout << "Sparkly copy constructor called\n";
};
// Use of the scope resoultion operator '::' resolves ambiguity about
// which base class member should be accessed i.e. ClapTrap::operator=()
DiamondTrap&	DiamondTrap::operator=( const DiamondTrap& other ) {
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_name = other._name;
		this->setHp(FragTrap::getHp());
		this->setEnergy(ScavTrap::getEnergy());
		this->setDamage(FragTrap::getDamage());
	}
	std::cout << "Sparkly copy assignment constructor called\n";
	return *this;
};
DiamondTrap::~DiamondTrap() {
	std::cout << "Sparkly destructor called\n";
};

// Public Member Functions
void	DiamondTrap::whoAmI() {
	std::cout << "Oh my Glob, " << this->_name << " is here!\n";
};
// Use of the scope resoultion operator '::' resolves ambiguity about
// which base class member should be accessed i.e. ScavTrap::attack()
void	DiamondTrap::attack( const std::string& target ) {
	ScavTrap::attack(target);
}
