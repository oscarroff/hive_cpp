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

class	Fixed {
private:
	int	_whole; // Fixed point number to the left of the decimal
	int	_fraction; // Integer literal (base 8) e.g. 0123 = 83 in base 10
public:
	Fixed();
	Fixed( const Fixed& other );
	Fixed&	operator=( const Fixed& other );
	~Fixed();
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};
