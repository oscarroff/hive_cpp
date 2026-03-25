/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:26:56 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/25 16:46:13 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WEAPON_H
# define WEAPON_H

# include <string>

class	Weapon {
private:
	std::string	_type;
public:
	Weapon( std::string type );
	~Weapon();
	const std::string	getType();
	void				setType( std::string type );
};

#endif
