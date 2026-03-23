/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:50:57 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/23 11:49:12 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

Zombie* zombieHorde( int N, std::string name );

int	main( int argc, char **argv )
{
	if (argc < 3)
	{
		std::cout << "Moar brainz! demands a number and a name...\n";
		return (EXIT_FAILURE);
	}
	int	loadsOfEm = std::stoi(argv[1]);
	if (loadsOfEm < 1)
	{
		std::cout << "Moar brainz! demands more...\n";
		return (EXIT_FAILURE);
	}
	std::string	name = argv[2];
	if (name.empty())
	{
		std::cout << "Moar brainz! demands a name...\n";
		return (EXIT_FAILURE);
	}
	Zombie*	horde = zombieHorde(loadsOfEm, name);
	std::allocator<Zombie>	disbandHorde;
	for (int i = 0; i < loadsOfEm; i++) {
		horde[i].announce();
		disbandHorde.destroy(horde + i);
	}
	disbandHorde.deallocate(horde, loadsOfEm);
	return (EXIT_SUCCESS);
}
