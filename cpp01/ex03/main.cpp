/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:55:14 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/25 15:22:42 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main( void )
{
	Weapon club1 = Weapon("crude spiked club");
	HumanA bob("Bob", club1);
	bob.attack();
	club1.setType("some other type of club");
	bob.attack();
	Weapon club2 = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club2);
	jim.attack();
	club2.setType("some other type of club");
	jim.attack();
	return 0;
}
