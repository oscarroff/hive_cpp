/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 09:56:39 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/19 10:14:53 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

template <typename T>
class	Array {
private:
	T*		_array;
	size_t	_size;
public:
	// Constructors & Destructors
	Array();
	Array( const unsigned int n );
	Array( const Array& other );
	Array&	operator=( const Array& other );
	~Array();
	// Public Member Functions
	T&			operator[]( size_t index );
	const T&	operator[]( size_t index ) const;
	size_t		size();
};
