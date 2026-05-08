/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:35:25 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/07 14:48:08 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class	Ice : AMateria {
public:
	Ice();
	Ice( const Ice& other);
	Ice&	operator=( const Ice& other );
	~Ice();
	void	use(ICharacter& target) override;
	Ice*	clone() const override; 
};
