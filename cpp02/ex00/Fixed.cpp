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

Fixed::Fixed() : _whole(0) {};

Fixed::Fixed( const Fixed& other ) : _whole(other._whole) {};

Fixed& Fixed::operator=( const Fixed& other ) {
	this->_whole = other._whole;
	return *this;
};

Fixed::~Fixed() {};

int	Fixed::getRawBits( void ) {
	return ;
};

void	Fixed::setRawBits( const int raw ) {
	this->_whole = raw;
};
