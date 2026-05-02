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
#include "ClapTrap.hpp"
#include <iostream>

// Constructors & Destructors
ScavTrap::ScavTrap() : ClapTrap() {
	this->setHp(100);
	this->setEnergy(50);
	this->setDamage(20);
	std::cout << "Scavvy default constructor called\n";
};
ScavTrap::ScavTrap( const std::string name ) : ClapTrap(name) {
	this->setHp(100);
	this->setEnergy(50);
	this->setDamage(20);
	std::cout << "Scavvy named constructor called\n";
};
ScavTrap::ScavTrap( const ScavTrap& other ) : ClapTrap(other) {
	this->setHp(other.getHp());
	this->setEnergy(other.getEnergy());
	this->setDamage(other.getDamage());
	std::cout << "Scavvy copy constructor called\n";
};
ScavTrap&	ScavTrap::operator=( const ScavTrap& other ) {
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->setHp(other.getHp());
		this->setEnergy(other.getEnergy());
		this->setDamage(other.getDamage());
	}
	std::cout << "Scavvy copy assignment constructor called\n";
	return *this;
};
ScavTrap::~ScavTrap() {
	std::cout << "Scavvy destructor called\n";
};

// Public Member Functions
void	ScavTrap::guardGate() {
	std::cout << this->getName() << " is now in gate keeper mode!\n";
};
