/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:10:24 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/04 15:20:20 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class	Cat : public Animal {
public:
	// Constructors & Destructors
	Cat();
	Cat( const Cat& other );
	Cat& operator=( const Cat& other );
	~Cat();
	// Public Member Functions
	void	makeSound() const override ;
};
