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
Bureaucrat::Bureaucrat() : _name("Minion"), _grade(150) {};

Bureaucrat::Bureaucrat( const std::string& name, unsigned int grade ) : _name(name) {
	if (grade < 1)
		throw GradeTooHighException(this->_name);
	if (grade > 150)
		throw GradeTooLowException(this->_name);
	this->_grade = grade;
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
	if (this->_grade <= 1)
		throw GradeTooHighException(this->_name);
	this->_grade--;
};
void				Bureaucrat::downGrade() {
	if (this->_grade >= 150)
		throw GradeTooLowException(this->_name);
	this->_grade++;
};

// Custom Exceptions
Bureaucrat::GradeTooHighException::GradeTooHighException( const std::string& name ) {
	this->_message = name + "'s grade is too high!\n";
};
const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return this->_message.c_str();
};
Bureaucrat::GradeTooLowException::GradeTooLowException( const std::string& name ) {
	this->_message = name + "'s grade is too low!\n";
};
const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return this->_message.c_str();
};

// Outstream Overload
std::ostream&	operator<<( std::ostream& out, const Bureaucrat& in ) {
	out << in.getName() << ", bureaucrat grade " << in.getGrade() << ".";
	return out;
};
