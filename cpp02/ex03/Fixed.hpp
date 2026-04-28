/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 12:43:27 by thblack-          #+#    #+#             */
/*   Updated: 2026/04/08 14:20:16 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

# define FRACTIONAL_BITS 8

class	Fixed {
private:
	int	_value; // Integer to store the fixed-point number value
	static const int	_fractionalBits = FRACTIONAL_BITS; // The number of fractional bits
public:
	// Orthodoc Canonical Form functions
	Fixed();
	Fixed( const Fixed& other );
	Fixed&	operator=( const Fixed& other );
	~Fixed();
	// Overloaded copy functions
	Fixed( const int& integer );
	Fixed( const float& floatingPoint );
	// Utility Functions
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
	// Overloaded comparison operators
	bool	operator>( const Fixed& other) const;
	bool	operator<( const Fixed& other) const;
	bool	operator>=( const Fixed& other) const;
	bool	operator<=( const Fixed& other) const;
	bool	operator==( const Fixed& other) const;
	bool	operator!=( const Fixed& other) const;
	// Overloaded arithmetic operators
	Fixed	operator+( const Fixed& other ) const;
	Fixed	operator-( const Fixed& other ) const;
	Fixed	operator*( const Fixed& other ) const;
	Fixed	operator/( const Fixed& other ) const;
	// Overloaded increment & decrement operators
	Fixed&	operator++();
	Fixed	operator++( int );
	Fixed&	operator--();
	Fixed	operator--( int );
	// Overloaded comparison functions that return references
	// static Fixed&	min( Fixed& a, Fixed& b );
	// static const Fixed&	min( const Fixed& a, const Fixed& b );
	// static Fixed&	max( Fixed& a, Fixed& b );
	// static const Fixed&	max( const Fixed& a, const Fixed& b );
	static Fixed&	min( Fixed& a, Fixed& b ) {
		std::cout << "Minimum member (non const) function called\n";
		if (a <= b)
			return a;
		else
			return b;
	};
	static const Fixed&	min( const Fixed& a, const Fixed& b ) {
		std::cout << "Minimum member (const) function called\n";
		if (a <= b)
			return a;
		else
			return b;
	};
	static Fixed&	max( Fixed& a, Fixed& b ) {
		std::cout << "Maximum member (non const) function called\n";
		if (a >= b)
			return a;
		else
			return b;
	};
	static const Fixed&	max( const Fixed& a, const Fixed& b ) {
		std::cout << "Maximum member (const) function called\n";
		if (a >= b)
			return a;
		else
			return b;
	};
};

// Notes: const after function indicates no change to *this

std::ostream& operator<<(std::ostream& out, const Fixed& in);
