/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:32:40 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/25 15:21:44 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef HUMANB_H
# define HUMANB_H

# include <iostream>
# include "Weapon.hpp"

class	HumanB {
private:
	std::string	_name;
	Weapon*		_weapon;
public:
	HumanB( std::string name );
	~HumanB();
	void	attack();
	void	setWeapon( Weapon& weapon );
};
#endif
