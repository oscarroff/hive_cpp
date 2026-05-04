/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:04:05 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/04 15:33:01 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	WrongAnimal {
protected:
	std::string	_type;
public:
	// Constructors & Destructors
	WrongAnimal();
	WrongAnimal( const std::string& type );
	WrongAnimal( const WrongAnimal& other );
	WrongAnimal& operator=( const WrongAnimal& other );
	virtual ~WrongAnimal();
	// Public Member Functions
	const std::string	getType( void ) const ;
	virtual void		makeSound() const ;
};
