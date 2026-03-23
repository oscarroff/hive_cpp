/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 10:59:46 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/23 11:39:40 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N < 1)
		return NULL;
	std::allocator<Zombie> hordeAssembler;
	Zombie*	horde = hordeAssembler.allocate(N);
	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}
	return horde;
}
