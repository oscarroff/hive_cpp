/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:00:46 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/08 14:23:47 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include <string>

// Forward declation of a class
class	ICharacter;

// AMateria is an abstract class
// (NOT a pure abstract class though AKA interface)
// An abstract class contains at least one pure virtual function
// An abstract class differs from an interface in that it does contain some
// code but still cannot be instantiated alone and its virtual methods can
// be overriden.

// A pure virtual FUNCTION is declared using '= 0' and has no implementation
// i.e. it doesn not appear in the *.cpp file. An abstract class contains at
// least one pure virtual function and serves as a blueprint for derived classes
// e.g. base Shape, child Triangle
// The constructors and destructors are declared '= default' which tells the
// compiler to generate default constructors

class	AMateria {
protected:
	std::string	_type;
public:
	// Constructors & Desctructors
	// Defaulted copy constructors are generally optional, included here as we
	// should use the Orthodox Canonical Form?
	AMateria() = default;
	AMateria( const AMateria& ) = default;
	AMateria&	operator=( const AMateria& ) = default;
	// Virtual destructor is essential if base class is to be used polymorphically
	virtual ~AMateria() = default;

	// Named constructor
	AMateria( const std::string& type );
	// Public Member Functions
	const std::string&	getType() const; // Returns the materia type
	// Classic solution to how to clone polymorphic objects that is only accesible
	// via the interface it implements, use clone()!
	// A more modern solution exists with std::unique_ptr, but we don't do that yet
	// here. https://www.fluentcpp.com/2017/09/08/make-polymorphic-copy-modern-cpp/
	virtual AMateria	*clone() const = 0; 
	virtual void		use(ICharacter& target);
};
