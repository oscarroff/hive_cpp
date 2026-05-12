/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:29:06 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/12 17:17:12 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <string>
#include <ostream>

// Forward Declaration
class	Bureaucrat;

class	Form {
private:
	const std::string	_name;
	bool				_signed;
	const unsigned int	_signGrade;
	const unsigned int	_execGrade;
public:
	// Constructors & Destructors
	Form();
	Form( const std::string& name, unsigned int signGrade, unsigned int execGrade );
	Form( const Form& other );
	Form& operator=( const Form& other );
	~Form();

	// Getters
	const std::string&	getName() const;
	bool				getSigned() const;
	unsigned int		getSignGrade() const;
	unsigned int		getExecGrade() const;

	// Other Member Functions
	void				beSigned( const Bureaucrat& b );

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

std::ostream&	operator<<( std::ostream& out, const Form& in );
