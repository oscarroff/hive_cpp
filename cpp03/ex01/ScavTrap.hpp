/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:55:15 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/03 13:09:20 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap {
public:
	// Constructors & Destructors
	ScavTrap();
	ScavTrap( const std::string& name );
	ScavTrap( const ScavTrap& other );
	ScavTrap& operator=( const ScavTrap& other );
	~ScavTrap();
	// Public Member Functions
	void	guardGate();
	void	attack( const std::string& target );
};
