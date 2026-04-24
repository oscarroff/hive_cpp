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
	Fixed();
	Fixed( const Fixed& other );
	Fixed( const int& integer );
	Fixed( const float& floatingPoint );
	Fixed&	operator=( const Fixed& other );
	~Fixed();
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& in);
