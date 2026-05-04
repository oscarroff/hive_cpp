/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:04:05 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/04 14:58:28 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	Animal {
protected:
	std::string	_type;
public:
	// Constructors & Destructors
	Animal();
	Animal( const std::string& type );
	Animal( const Animal& other );
	Animal& operator=( const Animal& other );
	virtual ~Animal();
	// Public Member Functions
	const std::string	getType( void ) const ;
	virtual void		makeSound() const ;
};
