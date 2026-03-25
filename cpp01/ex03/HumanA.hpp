/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:32:09 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/25 15:06:31 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef HUMANA_H
# define HUMANA_H

# include <iostream>
# include "Weapon.hpp"

class	HumanA {
private:
	std::string	_name;
	Weapon&		_weapon;
public:
	HumanA( std::string name, Weapon& weapon );
	~HumanA();
	void	attack();
};

#endif
