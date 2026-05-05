/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:55:33 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/03 13:14:09 by thblack-         ###   ########.fr       */
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
void	ScavTrap::attack( const std::string& target ) {
	if (this->getHp() < 1)
		std::cout << this->getName() << " is whacked out, attack failed!\n";
	else if (this->getEnergy() < 1)
		std::cout << this->getName() << " is out of beans, attack failed!\n";
	else
	{
		std::cout << this->getName() << " spanks " << target << "'s hams causing "
			<< this->getDamage() << " points of damage!\n";
		this->setEnergy(this->getEnergy() - 1);
	}
};
void	ScavTrap::guardGate() {
	std::cout << this->getName() << " is now in gate keeper mode!\n";
};
