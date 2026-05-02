/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:33:23 by thblack-          #+#    #+#             */
/*   Updated: 2026/04/29 13:53:21 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main( void ) {
	ScavTrap	NamelessHero;
	ScavTrap	Finn("Finn"), Jake("Jake"), Bmo("BMO"), \
		Bubblegum("Princess Bubblegum"), IceKing("IceKing");
	ScavTrap	Changeling(Finn);
	Changeling = Jake;
	Finn.attack("Jake");
	Jake.takeDamage(0);
	Bmo.attack("IceKing");
	IceKing.takeDamage(0);
	IceKing.attack("Princess Bubblegum");
	Bubblegum.takeDamage(0);
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
	Jake.guardGate();
	Changeling.beRepaired(100);
};
