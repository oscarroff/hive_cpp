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
#include <iostream>

int	main( void )
{
	Bureaucrat	sally("Sally", 1), bob("Bob", 75), rowan("Rowan", 150);
	std::cout << sally << "\n";
	std::cout << bob << "\n";
	std::cout << rowan << "\n\n";

	Form	form("Parking Ticket", 50, 1);
	std::cout << form << "\n";

	std::cout << "\n";

	rowan.signForm(form);
	bob.signForm(form);
	sally.signForm(form);

	std::cout << "\n";

	try {
		Form	toiletPaper("Toilet Paper", 1000, 42000);
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}
	try {
		Form	goldenTicket("Willy Wonka Admit One", 10, 0);
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}
