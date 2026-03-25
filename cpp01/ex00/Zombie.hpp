/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:51:34 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/25 16:47:40 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>

class	Zombie {
private:
	std::string	_name;
public:
	Zombie( std::string name );
	~Zombie( void );
	std::string	getName( void );
	void		announce( void );
};

#endif
