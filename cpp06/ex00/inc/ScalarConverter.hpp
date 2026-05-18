/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:48:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/17 16:47:56 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string> // for std::string

// Scalar types are all arithmetic types plus enums, pointers and std::nullptr_t
// Our scalar converter will take a string representation of a C++ literal and
// output the same value in the forms:
// - char e.g. 'c'
// - int e.g. '42'
// - float e.g. '4.2f'
// - double e.g.'4.2'
// Additionally +/-inff (float) and +/-inf (double) will be handled
//
// We first convert to actual type (runtime casting with 'dynamic_cast<type>')
// then explicit casting to the three other data types.

class ScalarConverter {
private:
    // Constructors & Destructors
    ScalarConverter();
    ScalarConverter( const ScalarConverter& other );
    ScalarConverter &operator=( const ScalarConverter &other );
    virtual ~ScalarConverter();
public:
    // Static member function
    // - can be called without creating an object
    // - only has access to static data members or other static functions
    static void convert( const std::string& literal );
};
