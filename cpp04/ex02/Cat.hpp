/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:10:24 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/04 16:57:17 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class	Cat : public AAnimal {
private:
	Brain*			_brain;
public:
	// Constructors & Destructors
	Cat();
	Cat( const Cat& other );
	Cat& operator=( const Cat& other );
	~Cat() override;
	// Public Member Functions
	void	makeSound() const override ;
	Brain*	mindMeld() const ;
};
