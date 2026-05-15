/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:48:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/13 10:48:55 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Default constructor
ScalarConverter::ScalarConverter() {};

// Copy constructor
ScalarConverter::ScalarConverter( const ScalarConverter& other ) { (void)other; };

// Copy assignment operator
ScalarConverter& ScalarConverter::operator=( const ScalarConverter& other ) {
    (void)other;
    return *this;
}

// Destructor
ScalarConverter::~ScalarConverter() {};
