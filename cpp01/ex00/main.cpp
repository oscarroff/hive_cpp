/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:50:57 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/19 18:25:01 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int	main( void )
{
	Zombie* heapZombie = newZombie("Bob the Heap");
	heapZombie->announce();
	delete	heapZombie;
	randomChump("Barry the Stack");
	return (EXIT_SUCCESS);
}
