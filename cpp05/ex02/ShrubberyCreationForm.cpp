/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:48:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/13 18:49:55 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <string>
#include <bits/stdc++.h>

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("DefaultShrub", 145, 137) {};

// Target constructor
ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target )
: AForm("DefaultShrub", 145, 137), _target(target) {};

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other )
: AForm(other.getName(), 145, 137) {};

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {};

// Member Functions
const std::string&	ShrubberyCreationForm::getTarget() const {
	return this->_target;
};

void	ShrubberyCreationForm::doThings() const {
	// Create <target>_shrubbery in the working directory and write ASCII trees
	std::string		output_filename = this->getTarget() + "_shrubbery";
	std::ofstream	output(output_filename);
	if (!output.is_open()) {
		throw Bureaucrat::ExecutionFailException("shrubbery doThings() failed to open file");
	}
	output << SHRUBS;
	output.close();
};
