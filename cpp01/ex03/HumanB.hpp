/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:32:40 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/25 16:46:34 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef HUMANB_H
# define HUMANB_H

# include <string>
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
