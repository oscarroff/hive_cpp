/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:55:15 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/04 18:09:22 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap , public FragTrap {
private:
	std::string	_name;
public:
	// Constructors & Destructors
	DiamondTrap();
	DiamondTrap( std::string name );
	DiamondTrap( const DiamondTrap& other );
	DiamondTrap& operator=( const DiamondTrap& other );
	~DiamondTrap();
	// Public Member Functions
	void	whoAmI();
	void	attack( const std::string& target );
};
