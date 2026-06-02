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
#include <bits/stdc++.h> // for std::ifstream
#include <cstdlib>
#include <stdexcept> // for exceptions

// Copy constructor
BitcoinExchange::BitcoinExchange( const BitcoinExchange& other )
	: _database(other._database) {};

// Copy assignment operator
BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& other ) {
	if (this != &other)
		this->_database = other._database;
	return *this;
}

// Destructor
BitcoinExchange::~BitcoinExchange() {};

// Build constructor
BitcoinExchange::BitcoinExchange( const char* path ) {;
	loadCSV(path);
};

// Public member functions
std::map<time_t, int>&	BitcoinExchange::getMap() {
	return this->_database;
};

static time_t	parseDate( const char* dateTimeString ) {
	struct std::tm	tmStruct;
	strptime(dateTimeString, "%Y-%m-%d", &tmStruct);
	return mktime(&tmStruct);
}

void    BitcoinExchange::loadCSV( const char* path ) {
	std::ifstream	file(path);
	if (!file.is_open())
		throw std::runtime_error("could not open file");
	std::string	line;
	time_t		date;
	int		value;

	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("invalid header");
	while (std::getline(file, line)) {
		date = parseDate(line.substr(0, 10).c_str());
		value = std::stoi(line.substr(11));
		this->_database.insert({date, value});
	}
	file.close();
};
