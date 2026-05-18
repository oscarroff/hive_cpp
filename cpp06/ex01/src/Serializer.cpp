/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:48:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/18 10:03:06 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*
 * Serializer
 *
 * An exercise using the c++ casting operator 'reinterpret_cast'
 * This casting operator guarantees that if you cast a pointer to a different
 * type, and then reinterpret_cast back to the original type, then we get the
 * original value. E.g. in this example a and c contain the same value, but 
 * b is unspecified.
 *
 * int* a = new int();
 * void* b = reinterpret_cast<void*>(a);
 * int* c = reinterpret_cast<int*>(b);
 *
 * This is different to static_cast where the address is preserved throughout.
*/

uintptr_t	Serializer::serialize( Data *ptr ) {
	return reinterpret_cast<uintptr_t>(ptr);
};
Data*		Serializer::deserialize( uintptr_t raw ) {
	return reinterpret_cast<Data*>(raw);
};
