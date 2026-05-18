/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:29:06 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/13 11:30:44 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <string>
#include <ostream>

// Forward Declaration
class	Bureaucrat;

class	AForm {
private:
	const std::string	_name;
	bool				_signed;
	const unsigned int	_signGrade;
	const unsigned int	_execGrade;
public:
	// Constructors & Destructors
	AForm();
	AForm( const std::string& name, unsigned int signGrade, unsigned int execGrade );
	AForm( const AForm& other );
	AForm& operator=( const AForm& other );
	virtual ~AForm() = default;

	// Getters
	const std::string&	getName() const;
	bool				getSigned() const;
	unsigned int		getSignGrade() const;
	unsigned int		getExecGrade() const;

	// Other Member Functions
	void			beSigned( const Bureaucrat& b );
	void			execute( const Bureaucrat& executor ) const;
	virtual void	doThings() const = 0;

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
	// Custom Exceptions
	class	ExecutionFailException : public std::exception {
	private:
		std::string	_message;
	public:
		ExecutionFailException( const std::string& message );
		const char*	what() const noexcept override;
	};
};

std::ostream&	operator<<( std::ostream& out, const AForm& in );
