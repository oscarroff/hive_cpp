/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:12:51 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/12 16:48:47 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"
#include <exception>
#include <string>

// Forward Declaration
class	Form;

class	Bureaucrat {
private:
	const std::string	_name;
	unsigned int		_grade;
public:
	// Constructors & Destructors
	Bureaucrat();
	Bureaucrat( const std::string& name, unsigned int grade );
	Bureaucrat( const Bureaucrat& other );
	Bureaucrat& operator=( const Bureaucrat& other );
	~Bureaucrat();

	// Setters & Getters
	const std::string&	getName() const;
	unsigned int		getGrade() const;
	void				upGrade();
	void				downGrade();

	// Other Member Functions
	void				signForm( Form& f ) const;

	// Custom Exceptions
	class	GradeTooHighException : public std::exception {
	private:
		std::string	_message;
	public:
		GradeTooHighException( const std::string& name );
		const char*	what() const noexcept override;
	};
	class	GradeTooLowException : public std::exception {
	private:
		std::string	_message;
	public:
		GradeTooLowException( const std::string& name );
		const char*	what() const noexcept override;
	};
};

std::ostream&	operator<<( std::ostream& out, const Bureaucrat& in );
