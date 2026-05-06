/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:55:15 by thblack-          #+#    #+#             */
/*   Updated: 2026/04/29 14:27:47 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap {
public:
	// Constructors & Destructors
	ScavTrap();
	ScavTrap( std::string name );
	ScavTrap( const ScavTrap& other );
	ScavTrap& operator=( const ScavTrap& other );
	~ScavTrap();
	// Public Member Functions
	void	guardGate();
	// Override of virtual function in the parent class
	void	attack( const std::string& target ) override ;
};
