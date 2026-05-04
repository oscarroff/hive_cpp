/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:33:23 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/03 13:22:11 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main( void ) {
	DiamondTrap	NamelessHero;
	DiamondTrap	Finn("Finn"), Jake("Jake"), Bmo("BMO"), \
		Bubblegum("Princess Bubblegum"), IceKing("IceKing");
	Finn.attack("Jake");
	Finn.whoAmI();
	Jake.takeDamage(0);
	Jake.whoAmI();
	Bmo.attack("IceKing");
	Bmo.whoAmI();
	IceKing.takeDamage(0);
	IceKing.attack("Princess Bubblegum");
	IceKing.whoAmI();
	Bubblegum.takeDamage(0);
	Bubblegum.whoAmI();
	Bmo.beRepaired(1);
	Bmo.attack("IceKing");
	Bmo.attack("IceKing");
	Bmo.attack("IceKing");
	Bmo.attack("IceKing");
	Bmo.attack("IceKing");
	Bmo.attack("IceKing");
	Bmo.attack("IceKing");
	Bmo.attack("IceKing");
	Bmo.attack("IceKing");
	Jake.highFivesGuys();
	DiamondTrap	Changeling(Finn);
	Changeling.beRepaired(100);
	Changeling.whoAmI();
	Changeling = Jake;
	Changeling.beRepaired(100);
	Changeling.whoAmI();
};
