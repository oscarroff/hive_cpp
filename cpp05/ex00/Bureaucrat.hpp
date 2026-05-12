/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:12:51 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/12 15:06:02 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <string>

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

	// Custom Exceptions
	class	GradeTooHighException : public std::exception {
	private:
		int	_value;
	public:
		GradeTooHighException( int value );
		const char*	what() const noexcept override;
		int	getValue() const;
	};
	class	GradeTooLowException : public std::exception {
	private:
		int	_value;
	public:
		GradeTooLowException( int value );
		const char*	what() const noexcept override;
		int	getValue() const;
	};
};
