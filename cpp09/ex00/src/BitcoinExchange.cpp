/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:48:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/13 10:48:55 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Default constructor
BitcoinExchange::BitcoinExchange() {};

// Copy constructor
BitcoinExchange::BitcoinExchange( const BitcoinExchange& other ) { (void)other; };

// Copy assignment operator
BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& other ) {
    (void)other;
    return *this;
}

// Destructor
BitcoinExchange::~BitcoinExchange() {};
