/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:33:16 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/12 17:17:20 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

// Constructors & Destructors
AForm::AForm() : _name("BlankPaper"), _signed(false), _signGrade(150), _execGrade(150) {};

AForm::AForm( const std::string& name, unsigned int signGrade, unsigned int execGrade )
: _name(name), _signed(false),
	_signGrade([signGrade, name]() {
		if (signGrade < 1)
			throw GradeTooHighException(name + "'s sign");
		if (signGrade > 150)
			throw GradeTooLowException(name + "'s sign");
		return signGrade;
	}()),
	_execGrade([execGrade, name]() {
		if (execGrade < 1)
			throw GradeTooHighException(name + "'s execution");
		if (execGrade > 150)
			throw GradeTooLowException(name + "'s execution");
		return execGrade;
	}()) {};

AForm::AForm( const AForm& other )
: _name(other._name), _signed(false), _signGrade(other._signGrade), _execGrade(other._execGrade) {};

AForm&			AForm::operator=( const AForm& other ) {
	if (this != &other) {
		this->_signed = other.getSigned();
	}
	return *this;
};

AForm::~AForm() {};

// Getters
const std::string&	AForm::getName() const { return this->_name; };
bool				AForm::getSigned() const { return this->_signed; };
unsigned int		AForm::getSignGrade() const { return this->_signGrade; };
unsigned int		AForm::getExecGrade() const { return this->_execGrade; };

// Other Member Functions
void				AForm::beSigned( const Bureaucrat& b ) {
	if (b.getGrade() > this->_signGrade)
		throw GradeTooLowException(b.getName());
	this->_signed = true;
};

// Custom Exceptions
AForm::GradeTooHighException::GradeTooHighException( const std::string& name ) {
	this->_message = name + " grade is too high!";
};
const char* AForm::GradeTooHighException::what() const noexcept {
	return this->_message.c_str();
};
AForm::GradeTooLowException::GradeTooLowException( const std::string& name ) {
	this->_message = name + " grade is too low!";
};
const char* AForm::GradeTooLowException::what() const noexcept {
	return this->_message.c_str();
};
AForm::ExecutionFailException::ExecutionFailException( const std::string& message ) {
	this->_message = message;
};
const char* AForm::ExecutionFailException::what() const noexcept {
	return this->_message.c_str();
};

void	AForm::execute( const Bureaucrat& executor ) const {
	if (!this->getSigned())
		throw ExecutionFailException("form is unsigned.");
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException(executor.getName());
	this->doThings();
};

// Outstream Overload
std::ostream&	operator<<( std::ostream& out, const AForm& in ) {
	out << in.getName() << " is " << (in.getSigned() ? "signed" : "unsigned")
		<< " and requires level " << in.getSignGrade()
		<< " for signing and level " << in.getExecGrade()
		<< " for execution.";
	return out;
};
