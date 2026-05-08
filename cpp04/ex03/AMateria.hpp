/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:00:46 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/07 13:57:50 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include <string>

// Forward declation of a class
class	ICharacter;

// AMateria is our pure abstract class otherwise known as an interface
// A pure virtual FUNCTION is declared using '= 0' and has no implementation
// i.e. it doesn not appear in the *.cpp file. An abstract class contains at
// least one pure virtual function and serves as a blueprint for derived classes
// e.g. base Shape, child Triangle
// The constructors and destructors are declared '= default' which tells the
// compiler to generate the constructors
class	AMateria {
protected:
	std::string	_type;
	// Construction controlled in protected to prevent direct instantiation
	AMateria() = default;
public:
	// Constructors & Desctructors
	// Defaulted copy constructors are generally optional, included here as we
	// should use the Orthodox Canonical Form
	AMateria( const AMateria& other ) = default;
	AMateria&	operator=( const AMateria& other ) = default;
	// Virtual destructor is essential if base class is to be used polymorphically
	virtual ~AMateria() = default;
	// Named constructor
	AMateria( const std::string& type );
	// Public Member Functions
	const std::string&	getType() const; // Returns the materia type
	virtual AMateria	*clone() const = 0; 
	virtual void		use(ICharacter& target);
};
