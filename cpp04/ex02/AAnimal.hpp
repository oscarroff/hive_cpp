/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:04:05 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/04 17:55:07 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

// Renamed to AAnimal to indicate it is now an abstract class (i.e. is not
// instantiable
class	AAnimal {
protected:
	std::string	_type;
	// Constructors are declared in protected to prevent instantiation of the
	// bass class
	AAnimal() = default;
	AAnimal( const AAnimal& other ) = default;
	AAnimal& operator=( const AAnimal& other ) = default;
public:
	// Constructors & Destructors
	virtual ~AAnimal() = default;
	// Public Member Functions
	const std::string	getType( void ) const ;
	void				setType( const std::string& type );
	virtual void		makeSound() const = 0;
};
