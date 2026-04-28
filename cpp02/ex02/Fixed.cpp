/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 12:43:24 by thblack-          #+#    #+#             */
/*   Updated: 2026/04/28 16:54:26 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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
// fractional bits) and thus places to the left of the decimal. We avoid using
// bit shifting as negative values result in undefined behaviour.
Fixed::Fixed( const int& integer ) {
	std::cout << "Int constructor called\n";
	this->_value = integer * (1 << this->_fractionalBits);
};

// Creates a Fixed object and sets the value to a float passed as a parameter.
// The integer is multiplied by 256 (our "resolution" with 8 fractional bits)
// and thus places to the left of the decimal. Rounding is used to make the
// calculation more accurate. We avoid using bit shifting as negative values
// result in undefined behaviour.
Fixed::Fixed( const float& floatingPoint ) {
	std::cout << "Float constructor called\n";
	this->_value = roundf(floatingPoint * (1 << this->_fractionalBits));
};

// An operator constructor that tells the compiler how to interpret syntax that
// includes Fixed = Fixed.
Fixed& Fixed::operator=( const Fixed& other ) {
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->_value = other._value;
	return *this;
};

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
};

// Fetches the raw value of number wihout any scaling applied
int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called\n";
	return this->_value;
};

// Sets the raw value of the number without any scaling applied
void	Fixed::setRawBits( const int raw ) {
	std::cout << "setRawBits member function called\n";
	this->_value = raw;
};

// Converts the number to an integer
int	Fixed::toInt( void ) const {
	return this->_value / (1 >> this->_fractionalBits);
};

// Converts the number to a float
float	Fixed::toFloat( void ) const {
	return (float)this->_value / (1 << this->_fractionalBits);
};

// Overloaded comparison operators
bool	Fixed::operator>( const Fixed& other) const {
	std::cout << "Greater than operator called\n";
	return this->_value > other._value;
};
bool	Fixed::operator<( const Fixed& other) const {
	std::cout << "Lesser than operator called\n";
	return this->_value < other._value;
};
bool	Fixed::operator>=( const Fixed& other) const {
	std::cout << "Greater or equal than operator called\n";
	return this->_value >= other._value;
};
bool	Fixed::operator<=( const Fixed& other) const {
	std::cout << "Lesser or equal than operator called\n";
	return this->_value <= other._value;
};
bool	Fixed::operator==( const Fixed& other) const {
	std::cout << "Equal operator called\n";
	return this->_value == other._value;
};

// Overloaded arithmetic operators
bool	Fixed::operator!=( const Fixed& other) const {
	std::cout << "Not equal operator called\n";
	return this->_value != other._value;
};
Fixed	Fixed::operator+( const Fixed& other ) const {
	std::cout << "Addition operator called\n";
	Fixed	result;
	result._value = this->_value + other._value;
	return result;
};
Fixed	Fixed::operator-( const Fixed& other ) const {
	std::cout << "Subtraction operator called\n";
	Fixed	result;
	result._value = this->_value - other._value;
	return result;
};
// Multiplication uses temporary conversion to long to protect against overflow
// then applies arithemetic instead of bit shifting to avoid undefined behaviour
// in the case of negative values
Fixed	Fixed::operator*( const Fixed& other ) const {
	std::cout << "Multiplication operator called\n";
	Fixed	result;
	result._value = ((long)this->_value * (long)other._value) / (1 << this->_fractionalBits);
	return result;
};
// Division uses temporary conversion to long to protect against overflow
// then applies arithemetic instead of bit shifting to avoid undefined behaviour
// in the case of negative values. Scaling up occurs first on *this to avoid
// loss of precision.
Fixed	Fixed::operator/( const Fixed& other ) const {
	std::cout << "Division operator called\n";
	Fixed	result;
	result._value = ((long)this->_value * (long)(1 << this->_fractionalBits)) / other._value;
	return result;
};

// Overloaded increment & decrement operators
Fixed&	Fixed::operator++() {
	std::cout << "Prefix increment called\n";
	this->_value++;
	return *this;
};
Fixed	Fixed::operator++(int) {
	std::cout << "Postfix increment called\n";
	Fixed	old = *this;
	operator++();
	return old;
};
Fixed&	Fixed::operator--() {
	std::cout << "Prefix decrement called\n";
	this->_value--;
	return *this;
};
Fixed	Fixed::operator--(int) {
	std::cout << "Postfix decrement called\n";
	Fixed	old = *this;
	operator--();
	return old;
};

std::ostream& operator<<(std::ostream& out, const Fixed& in)
{
    out << in.toFloat();
    return out;
}
