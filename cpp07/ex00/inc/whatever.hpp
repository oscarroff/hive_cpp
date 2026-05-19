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

/*
* Templates are a tool for creating generic classes or functions. They allow one
* function to work with multiple data types. Additionally they can be safer than
* using void* pointers and also form the basis of STL containers and alogrithms
* like vector, map and deque.
*
* Templates are defined using the 'template' keyword and parameters declared
* using the <typename A, typename B, ...>
*
* Templates can be used in:
* - Function templates (e.g. ex00 & ex01)
* - Class templates (e.g. ex02)
* - Template variables (e.g. pi example below)
*
* template <typename T> constexpr T pi = T(3.14159)
*/
template <typename T> void	swap( T& a, T& b ) {
	T	temp = a;
	a = b;
	b = temp;
};

template <typename T> T&	min( T& a, T& b ) {
	return b <= a ? b : a;
};

template <typename T> T&	max( T& a, T& b ) {
	return b >= a ? b : a;
};
