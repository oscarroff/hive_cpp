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

class	Animal {
protected:
	std::string	_type;
	Animal() = default;
	Animal( const Animal& other ) = default;
	Animal& operator=( const Animal& other ) = default;
public:
	// Constructors & Destructors
	virtual ~Animal() = default;
	// Public Member Functions
	const std::string	getType( void ) const ;
	void				setType( const std::string& type );
	virtual void		makeSound() const = 0;
};
