/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:35:25 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/08 15:07:45 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class	Cure : public AMateria {
public:
	Cure();
	Cure( const Cure& other);
	Cure&	operator=( const Cure& other ) = delete;
	~Cure() override;
	void	use(ICharacter& target) override;
	Cure*	clone() const override; 
	const std::string&	getType() const; // Returns the materia type
};
