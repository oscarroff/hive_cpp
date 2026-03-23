/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:51:34 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/23 11:26:40 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class	Zombie {
private:
	std::string	_name;
public:
	// Constructors & Deconstructors
	Zombie( std::string name );
	~Zombie( void );
	// Getters
	std::string	getName( void );
	void		announce( void );
	// Setters
	void	setName( std::string name );
};

#endif
