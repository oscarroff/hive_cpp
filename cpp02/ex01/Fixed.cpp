/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 12:43:24 by thblack-          #+#    #+#             */
/*   Updated: 2026/04/08 14:41:04 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Creates a Fixed object and initialised the value to 0
Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called\n";
};

// Creates a Fixed object and copies the value from a preexisting Fixed object
// passed as a parameter
Fixed::Fixed( const Fixed& other ) : _value(other._value) {
	std::cout << "Copy constructor called\n";
};

// Creates a Fixed object and sets the value to a whole integer passed as a
// parameter. The integer is multiplied by 256 (our "resolution" with 8
// fractional bits) and thus places to the left of the decimal.
Fixed::Fixed( const int& integer ) {
	std::cout << "Int constructor called\n";
	this->_value = integer << this->_fractionalBits;
};

// Creates a Fixed object and sets the value to a float passed as a parameter.
// The integer is multiplied by 256 (our "resolution" with 8 fractional bits)
// and thus places to the left of the decimal. Rounding is used to make the
// calculation more accurate.
Fixed::Fixed( const float& floatingPoint ) {
	std::cout << "Float constructor called\n";
	this->_value = roundf(floatingPoint * (1 << this->_fractionalBits));
};

// An operator constructor that tells the compiler how to interpret syntax that
// includes Fixed = Fixed.
Fixed& Fixed::operator=( const Fixed& other ) {
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
};

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
};

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called\n";
	return this->_value;
};

void	Fixed::setRawBits( const int raw ) {
	std::cout << "setRawBits member function called\n";
	this->_value = raw;
};

int		Fixed::toInt( void ) const {
	return this->_value >> this->_fractionalBits;
};

float	Fixed::toFloat( void ) const {
	return (float)this->_value / (1 << this->_fractionalBits);
};

std::ostream& operator<<(std::ostream& out, const Fixed& in)
{
    out << in.toFloat();
    return out;
}
