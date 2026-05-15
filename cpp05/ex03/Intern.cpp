/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:48:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/15 12:24:45 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Default constructor
Intern::Intern() {};

// Copy constructor
Intern::Intern( const Intern& other ) { (void)other; };

// Copy assignment constructor
Intern& Intern::operator=( const Intern& other ) {
    (void)other;
    return (*this);
}

// Destructor
Intern::~Intern() {};

enum	Forms {
	shrubberyForm,
	robotomyForm,
	pardonForm,
	invalidForm,
};

Forms	resolveForm( std::string input ) {
	for (size_t i = 0; i < input.size(); i++)
		input[i] = std::tolower(input[i]);
	if (input == "shrubbery"
		|| input == "shrubbery form"
		|| input == "shrubbery creation form") return shrubberyForm;
	if (input == "robotomy"
		|| input == "robotomy form"
		|| input == "robotomy request"
		|| input == "robotomy request form") return robotomyForm;
	if (input == "pardon"
		|| input == "pardon form"
		|| input == "presidential form"
		|| input == "presidential pardon"
		|| input == "presidential pardon form") return pardonForm;
	return invalidForm;
};

// Member Functions
AForm*	Intern::makeForm( const std::string& name, const std::string& target ) const {
	Forms	formType = resolveForm(name);
	AForm*	form;
	switch (formType) {
		case shrubberyForm: {
			form = new ShrubberyCreationForm(target);
			break ;
		};
		case robotomyForm: {
			form = new RobotomyRequestForm(target);
			break ;
		};
		case pardonForm: {
			form = new PresidentialPardonForm(target);
			break ;
		};
		case invalidForm: {
			std::cerr << "Intern cannot find a form matching the name " << name << "!\n";
			return nullptr;
		};
	}
	std::cout << "Intern creates " << form->getName() << ".\n";
	return form;
};
