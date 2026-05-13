/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:48:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/13 18:49:46 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <string>
#include <bits/stdc++.h>

// Default constructor
PresidentialPardonForm::PresidentialPardonForm()
: AForm("DefaultPardon", 25, 5) {};

// Target constructor
PresidentialPardonForm::PresidentialPardonForm( const std::string& target )
: AForm("DefaultPardon", 25, 5), _target(target) {};

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other )
: AForm(other.getName(), 25, 5), _target(other.getTarget()) {};

// Copy assignment constructor
PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm& other ) {
	if (this != &other) {
		this->_target = other.getTarget();
	}
	return *this;
};

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {};

// Member Functions
const std::string&	PresidentialPardonForm::getTarget() const {
	return this->_target;
};

void	PresidentialPardonForm::doThings() const {
	// Informs that <target> has been pardoned by Zaphod Beeblebrox.
	std::cout << this->getTarget() << " has been pardoned by Big Z, Worst Dressed Sentient Being in the Known Universe and one hoopy frood, President Zaphod Beebkebrox!\n";
};
