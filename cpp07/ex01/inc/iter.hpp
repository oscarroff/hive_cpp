/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:27:22 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/18 17:41:29 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iostream>

template <typename T>
void	printArray( const size_t i, T& element ) {
	std::cout << i << ": " << element << "\n";
};

template <typename T>
void	increment( T& element ) {
	element++;
};

template <typename T>
void	decrement( T& element ) {
	element--;
};

// iter() function template 
// Accepts:
// 1. address of an array
// 2. length of the array passed as const
// 3. function called on every element
// N.B. F&& is a perfect forwarding for c++11 onwards that accepts both
// lvalues and rvalues i.e. const and non-const references
//
// requires keyword (C++20)
// Specifies certain requirements about the variables passed as parameters.
// Allows us to overload with different types of functions passed to the function
// pointer. E.g. here we allow the function to have the forms:
// 1. func(index, element)
// 2. func(element)

template <typename T, typename F>
void	iter( T* array, const size_t len, F&& f )
	requires	requires( F func, size_t i, T t ) { func(i, t); }
{
	for (size_t i = 0; i < len; i++) {
		f(i, array[i]);
	};
};

template <typename T, typename F>
void	iter( T* array, const size_t len, F&& f )
	requires	requires( F func, T t ) { func(t); }
{
	for (size_t i = 0; i < len; i++) {
		f(array[i]);
	};
};
