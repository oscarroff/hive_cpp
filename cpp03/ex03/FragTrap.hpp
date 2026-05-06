/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:55:15 by thblack-          #+#    #+#             */
/*   Updated: 2026/04/29 14:27:47 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

// ClapTrap now inherits from ClapTrap virtually which ensures a sngle shared
// instance of the base class regardless of how many times it is inherited
class	FragTrap : virtual public ClapTrap {
public:
	// Constructors & Destructors
	FragTrap();
	FragTrap( std::string name );
	FragTrap( const FragTrap& other );
	FragTrap& operator=( const FragTrap& other );
	~FragTrap();
	// Public Member Functions
	void	highFivesGuys( void );
};
