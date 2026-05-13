/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:24:04 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/12 17:18:13 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int	main( void )
{
	Bureaucrat	sally("Sally", 1), bob("Bob", 75), rowan("Rowan", 150);
	std::cout << sally << "\n";
	std::cout << bob << "\n";
	std::cout << rowan << "\n";

	std::cout << "\n=== SHRUBBERY TESTS ===\n";

	AForm*	shrub = new ShrubberyCreationForm("mistyWood");
	std::cout << *shrub;

	std::cout << "\n";

	rowan.signForm(*shrub);

	std::cout << "\n";
	std::cout << *shrub;
	std::cout << "\n";

	bob.signForm(*shrub);

	std::cout << "\n";
	std::cout << *shrub;
	std::cout << "\n";

	rowan.executeForm(*shrub);
	bob.executeForm(*shrub);

	delete shrub;

	std::cout << "\n=== ROBOTOMY TESTS ===\n";

	AForm*	robo = new RobotomyRequestForm("eggMan");

	std::cout << "\n";

	rowan.signForm(*robo);

	std::cout << "\n";
	std::cout << *robo;
	std::cout << "\n";

	bob.signForm(*robo);

	std::cout << "\n";
	std::cout << *robo;
	std::cout << "\n";

	sally.signForm(*robo);

	std::cout << "\n";
	std::cout << *robo;
	std::cout << "\n";

	rowan.executeForm(*robo);
	bob.executeForm(*robo);
	sally.executeForm(*robo);

	delete robo;

	std::cout << "\n=== PARDON TESTS ===\n";

	AForm*	pardon = new PresidentialPardonForm("trillian");

	std::cout << "\n";

	rowan.signForm(*pardon);

	std::cout << "\n";
	std::cout << *pardon;
	std::cout << "\n";

	bob.signForm(*pardon);

	std::cout << "\n";
	std::cout << *pardon;
	std::cout << "\n";

	sally.signForm(*pardon);

	std::cout << "\n";
	std::cout << *pardon;
	std::cout << "\n";

	rowan.executeForm(*pardon);
	bob.executeForm(*pardon);
	sally.executeForm(*pardon);

	delete pardon;

	std::cout << "\n";

	return 0;
}
