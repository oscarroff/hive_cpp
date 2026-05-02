/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:55:33 by thblack-          #+#    #+#             */
/*   Updated: 2026/04/29 14:31:54 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

// Constructors & Destructors
DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {
	this->setHp(100);
	this->setEnergy(50);
	this->setDamage(20);
	std::cout << "Sparkly default constructor called\n";
};
DiamondTrap::DiamondTrap( const std::string name ) : ScavTrap(name) {
	this->setHp(100);
	this->setEnergy(50);
	this->setDamage(20);
	std::cout << "Sparkly named constructor called\n";
};
DiamondTrap::DiamondTrap( const DiamondTrap& other ) : ClapTrap(other) {
	this->setHp(other.getHp());
	this->setEnergy(other.getEnergy());
	this->setDamage(other.getDamage());
	std::cout << "Sparkly copy constructor called\n";
};
DiamondTrap&	DiamondTrap::operator=( const DiamondTrap& other ) {
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->setHp(other.getHp());
		this->setEnergy(other.getEnergy());
		this->setDamage(other.getDamage());
	}
	std::cout << "Sparkly copy assignment constructor called\n";
	return *this;
};
DiamondTrap::~DiamondTrap() {
	std::cout << "Sparkly destructor called\n";
};

// Public Member Functions
void	DiamondTrap::guardGate() {
	std::cout << this->getName() << " is now in gate keeper mode!\n";
};
