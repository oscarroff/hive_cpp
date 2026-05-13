/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:48:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/13 18:51:24 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <string>
#include <bits/stdc++.h>
#include <random>

// Default constructor
RobotomyRequestForm::RobotomyRequestForm()
: AForm("DefaultRobotomy", 72, 45) {};

// Target constructor
RobotomyRequestForm::RobotomyRequestForm( const std::string& target )
: AForm("DefaultRobotomy", 72, 45), _target(target) {};

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other )
: AForm(other.getName(), 72, 45) {};

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {};

// Member Functions
const std::string&	RobotomyRequestForm::getTarget() const {
	return this->_target;
};

bool	randomBool() {
	static std::mt19937 eng{std::random_device{}()};
	static std::uniform_int_distribution<int> dist(0, 1);
	return dist(eng);
};

void	RobotomyRequestForm::doThings() const {
	// Makes some drilling noises, then informs that <target> has been 
	// robotomized successfully 50% of the time.
	std::cout << "* drilling noises *\n";
	if (randomBool())
		std::cout << this->getTarget() << " has been robotomized.\n";
	else
		throw Bureaucrat::ExecutionFailException("robotomy doThings() failed to robotomize.");
};
