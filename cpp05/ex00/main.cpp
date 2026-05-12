/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:24:04 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/12 16:52:03 by thblack-         ###   ########.fr       */
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
	try {
		rowan.upGrade();
		bob.upGrade();
		sally.upGrade();
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what();
	}
	std::cout << "\n" << sally << "\n";
	std::cout << bob << "\n";
	std::cout << rowan << "\n\n";
	try {
		sally.downGrade();
		bob.downGrade();
		bob.downGrade();
		rowan.downGrade();
		rowan.downGrade();
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what();
	}
	std::cout << "\n" << sally << "\n";
	std::cout << bob << "\n";
	std::cout << rowan << "\n\n";
	try {
		Bureaucrat	lemon("Lemon", 1000);
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what();
	}
	std::cout << "\n";
	try {
		Bureaucrat	pet("Pet", 0);
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what();
	}
	return 0;
}
