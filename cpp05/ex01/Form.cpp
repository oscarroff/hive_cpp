/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:33:16 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/12 17:17:20 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors & Destructors
Form::Form() : _name("BlankPaper"), _signed(false), _signGrade(0), _execGrade(0) {};
Form::Form( const std::string& name, unsigned int signGrade, unsigned int execGrade )
: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {};
Form::Form( const Form& other )
: _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {};
Form&			Form::operator=( const Form& other ) {
	if (this != &other) {
		this->_signed = other.getSigned();
	}
	return *this;
};
Form::~Form() {};

// Getters
const std::string&	Form::getName() const { return this->_name; };
bool				Form::getSigned() const { return this->_signed; };
unsigned int		Form::getSignGrade() const { return this->_signGrade; };
unsigned int		Form::getExecGrade() const { return this->_execGrade; };

// Other Member Functions
void				Form::beSigned( const Bureaucrat& b ) {
	if (b.getGrade() > this->_signGrade)
		throw GradeTooLowException(b.getName());
};
//
// Custom Exceptions
Form::GradeTooHighException::GradeTooHighException( const std::string& name ) {
	this->_message = name + "'s grade is too high!";
};
const char* Form::GradeTooHighException::what() const noexcept {
	return this->_message.c_str();
};
Form::GradeTooLowException::GradeTooLowException( const std::string& name ) {
	this->_message = name + "'s grade is too low!";
};
const char* Form::GradeTooLowException::what() const noexcept {
	return this->_message.c_str();
};

// Outstream Overload
std::ostream&	operator<<( std::ostream& out, const Form& in ) {
	out << in.getName() << " is " << (in.getSigned() ? "signed" : "unsigned")
		<< " and requires level " << in.getSignGrade()
		<< " for signing and level " << in.getExecGrade()
		<< " for execution.\n";
	return out;
};
