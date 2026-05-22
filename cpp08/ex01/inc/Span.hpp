/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:48:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/20 09:11:19 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef> // for size_t
#include <exception> // for std::exception
#include <string> // for std::string

class Span {
private:
	int*	_array;
	size_t	_size;
	size_t	_capacity;

	void	getMinMax( int& min, int& max ) const;
public:
	// Constructors & Destructors
	Span();
	Span( const unsigned int N );
	Span( const Span &other );
	Span &operator=( const Span &other );
	~Span();

	// Getters
	int		at( const size_t i ) const;
	size_t	getSize() const;

	// Public Member Functions
	void			addNumber( const int num );
	unsigned int	longestSpan() const;
	unsigned int	shortestSpan() const;
	void			addRange( const size_t position, int first, int last );

	// Custom Exceptions
	class	FullException : public std::exception {
	private:
		std::string	_message;
	public:
		FullException( const std::string& name );
		const char*	what() const noexcept override;
	};

	class	SpanException : public std::exception {
	private:
		std::string	_message;
	public:
		SpanException( const std::string& name );
		const char*	what() const noexcept override;
	};

	class	IndexException : public std::exception {
	private:
		std::string	_message;
	public:
		IndexException( const std::string& name );
		const char*	what() const noexcept override;
	};
};

std::ostream&	operator<<( std::ostream& out, const Span& in );
