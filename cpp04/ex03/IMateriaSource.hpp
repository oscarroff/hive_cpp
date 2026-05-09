/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:51:00 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/07 14:54:41 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class	IMateriaSource
{
public:
	// Curly brackets {} denote an empty function body meaning the virtual
	// destructor does nothing except default behaviour. This ensures that
	// derived concrete class destructors are called.
	virtual	~IMateriaSource() {};
	virtual void		learnMateria(AMateria*) = 0;
	virtual AMateria*	createMateria(std::string const &type) = 0;
};
