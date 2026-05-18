/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:48:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/18 10:02:55 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdint> // for uintptr_t
#include <string> // for std::string

struct	Data {
	int			_x;
	std::string	_name;
};

class Serializer {
private:
	// Constructors & Destructors
	Serializer() = default;
	Serializer( const Serializer &other ) = default;
	Serializer	&operator=( const Serializer &other ) = default;
	~Serializer() = default;
public:
	// Static member function
	// - can be called without creating an object
	// - only has access to static data members or other static functions
	static uintptr_t	serialize( Data* ptr );
	static Data*		deserialize( uintptr_t raw );
};
