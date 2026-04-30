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

#include "ClapTrap.hpp"

int	main( void ) {
	ClapTrap	Finn("Finn"), Jake("Jake"), Bmo("BMO"), \
		Bubblegum("Princess Bubblegum"), IceKing("IceKing");
	ClapTrap	Changeling(Finn);
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
	Changeling.beRepaired(100);
};
