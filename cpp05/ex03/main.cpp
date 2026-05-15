/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:24:04 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/15 12:23:11 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int	main( void ) {
	Intern	someRandomIntern;
	AForm	*rrf1, *rrf2, *rrf3, *rrf4;
	rrf1 = someRandomIntern.makeForm("robotomy request", "Bender");
	rrf2 = someRandomIntern.makeForm("shrubbery", "New New York");
	rrf3 = someRandomIntern.makeForm("Presidential Pardon Form", "Dr. Zoidberg");
	rrf4 = someRandomIntern.makeForm("robotomy president", "Bender");
	Bureaucrat	fry("Fry", 10);
	std::cout << "\n";
	fry.signForm(*rrf1);
	fry.executeForm(*rrf1);
	std::cout << "\n";
	fry.signForm(*rrf2);
	fry.executeForm(*rrf2);
	std::cout << "\n";
	fry.signForm(*rrf3);
	fry.executeForm(*rrf3);
	std::cout << "\n";
	if (!rrf4)
		std::cerr << fry.getName() << " couldn't sign the form because it doesn't exist!\n";
	else {
		fry.signForm(*rrf4);
		fry.executeForm(*rrf4);
	}
};
