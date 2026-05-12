/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:12:51 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/12 15:10:30 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

// Constructors & Destructors
Bureaucrat::Bureaucrat() : _name("Minion"), _grade(0) {};
Bureaucrat::Bureaucrat( const std::string& name, unsigned int grade ) : _name(name) {
	try {
		if (grade < 1)
			throw GradeTooHighException(this->_grade);
		if (grade > 150)
			throw GradeTooLowException(this->_grade);
		this->_grade = grade;
	}
	catch (const GradeTooHighException& e) {
		std::cout << e.what();
	}
	catch (const GradeTooLowException& e) {
		std::cout << e.what();
	}
};
Bureaucrat::Bureaucrat( const Bureaucrat& other )
: _name(other.getName()), _grade(other.getGrade()) {};
Bureaucrat&			Bureaucrat::operator=( const Bureaucrat& other ) {
	if (this != &other) {
		this->_grade = other.getGrade();
	}
	return *this;
};
Bureaucrat::~Bureaucrat() {};

// Setters & Getters
const std::string&	Bureaucrat::getName() const { return this->_name; };
unsigned int		Bureaucrat::getGrade() const { return this->_grade; };
void				Bureaucrat::upGrade() {
	try {
		if (this->_grade <= 1)
			throw GradeTooHighException(this->_grade);
		this->_grade--;
	}
	catch (const GradeTooHighException& e) {
		std::cout << e.what();
	}
};
void				Bureaucrat::downGrade() {
	try {
		if (this->_grade >= 150)
			throw GradeTooLowException(this->_grade);
		this->_grade++;
	}
	catch (const GradeTooLowException& e) {
		std::cout << e.what();
	}
};

// Custom Exceptions
Bureaucrat::GradeTooHighException::GradeTooHighException( int value ) : _value(value) {};
const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return "Grade too high!\n";
};
int Bureaucrat::GradeTooHighException::getValue() const {
	return this->_value;
};
Bureaucrat::GradeTooLowException::GradeTooLowException( int value ) : _value(value) {};
const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return "Grade too low!\n";
};
int Bureaucrat::GradeTooLowException::getValue() const {
	return this->_value;
};

std::ostream&	operator<<( std::ostream& out, const Bureaucrat& in ) {
	out << in.getName() << ", bureaucrat grade " << in.getGrade();
	return out;
};
