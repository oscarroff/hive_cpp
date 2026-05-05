/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:55:15 by thblack-          #+#    #+#             */
/*   Updated: 2026/04/29 13:33:18 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	ClapTrap {
private:
	std::string	_name;
	int			_hp;
	int			_energy;
	int			_damage;
protected:
	// Setters & Getters
	void	setName( const std::string name );
	void	setHp( const int amount );
	void	setEnergy( const int amount );
	void	setDamage( const int amount );
	std::string		getName( void ) const;
	int		getHp( void ) const;
	int		getEnergy( void ) const;
	int		getDamage( void ) const;
public:
	// Constructors & Destructors
	ClapTrap();
	ClapTrap( const std::string& name );
	ClapTrap( const ClapTrap& other );
	ClapTrap& operator=( const ClapTrap& other );
	~ClapTrap();
	// Public Member Functions
	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );
};
