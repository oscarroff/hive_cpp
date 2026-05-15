/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:24:04 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/15 12:10:15 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

int	main( void ) {
	Intern	someRandomIntern;
	AForm	*rrf1, *rrf2, *rrf3, *rrf4;
	rrf1 = someRandomIntern.makeForm("robotomy request", "Bender");
	rrf2 = someRandomIntern.makeForm("shrubbery", "Bender");
	rrf3 = someRandomIntern.makeForm("Presidential Pardon Form", "Bender");
	rrf4 = someRandomIntern.makeForm("robotomy president", "Bender");
	Bureaucrat	fry("Fry", 10);
	fry.signForm(*rrf1);
	fry.executeForm(*rrf1);
};
