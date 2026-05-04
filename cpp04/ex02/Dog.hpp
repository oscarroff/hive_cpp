/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:10:24 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/04 17:53:29 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal {
private:
	Brain*			_brain;
public:
	// Constructors & Destructors
	Dog();
	Dog( const Dog& other );
	Dog& operator=( const Dog& other );
	~Dog();
	// Public Member Functions
	void	makeSound() const override ;
	Brain*	mindMeld() const ;
};
