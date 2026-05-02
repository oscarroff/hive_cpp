/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:55:33 by thblack-          #+#    #+#             */
/*   Updated: 2026/04/29 14:31:54 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

// Constructors & Destructors
FragTrap::FragTrap() : ClapTrap() {
	this->setHp(100);
	this->setEnergy(100);
	this->setDamage(30);
	std::cout << "Fraggy default constructor called\n";
};
FragTrap::FragTrap( const std::string name ) : ClapTrap(name) {
	this->setHp(100);
	this->setEnergy(100);
	this->setDamage(30);
	std::cout << "Fraggy named constructor called\n";
};
FragTrap::FragTrap( const FragTrap& other ) : ClapTrap(other) {
	this->setHp(other.getHp());
	this->setEnergy(other.getEnergy());
	this->setDamage(other.getDamage());
	std::cout << "Fraggy copy constructor called\n";
};
FragTrap&	FragTrap::operator=( const FragTrap& other ) {
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->setHp(other.getHp());
		this->setEnergy(other.getEnergy());
		this->setDamage(other.getDamage());
	}
	std::cout << "Fraggy copy assignment constructor called\n";
	return *this;
};
FragTrap::~FragTrap() {
	std::cout << "Fraggy destructor called\n";
};

// Public Member Functions
void	FragTrap::highFivesGuys( void ) {
	std::cout << this->getName() << " gives high fives! Choca esos cinco!\n";
};
