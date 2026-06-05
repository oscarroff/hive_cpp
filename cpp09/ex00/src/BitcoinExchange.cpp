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
#include <string>
#include <chrono>
#include <iostream>

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
std::map<ymd, int>&	BitcoinExchange::getDatabase() {
	return this->_database;
};

static std::optional<ymd>	parseDate( const std::string& dateString, char separator ) {
	int		year, month, day;
	char	s1, s2;
	std::stringstream	ss(dateString);
	if (!(ss >> year >> s1 >> month >> s2 >> day) ||
		s1 != separator || s2 != separator)
		return std::nullopt;
	auto y = std::chrono::year(year);
	auto m = std::chrono::month(month);
	auto d = std::chrono::day(day);
	auto	ymd = y / m / d;
	if (!ymd.ok())
		return std::nullopt;
	return ymd;
}

static int	parseValue( const std::string& numString ) {
	int	result = std::stoi(numString);
	result *= DECIMAL_FACTOR;
	int	fraction = 0;
	for (auto it = numString.find_first_of('.') + 1; it != numString.npos; it++) {
		fraction *= 10;
		fraction += it - 32;
	}
	result += fraction;
	return result;
}

int	BitcoinExchange::getValue( const std::string& dateString ) const {
	auto	it = this->_database.find(parseDate(dateString, DATE_SEPARATOR).value());
	if (it != this->_database.end())
		return it->second;
	return -1;
}

// static std::string	ft_dtos( time_t time ) {
// 	char	buffer[10];
// 	struct tm*	timeinfo = localtime(&time);
// 	strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
// 	return buffer;
// }

void    BitcoinExchange::loadCSV( const char* path ) {
	std::ifstream	file(path);
	if (!file.is_open())
		throw std::runtime_error("could not open file");
	std::string	line;
	std::optional<ymd>	date;
	int	value;

	std::getline(file, line);
	if (line != "date,exchange_rate") {
		file.close();
		throw std::runtime_error("invalid header");
	}
	while (std::getline(file, line)) {
		date = parseDate(line.substr(0, 10), DATE_SEPARATOR);
		if (!date.has_value()) {
			file.close();
			throw std::runtime_error("invalid date");
		}
		value = parseValue(line.substr(11));
		this->_database.insert({date.value(), value});
	}
	file.close();
};

// Custom exceptions
BitcoinExchange::ParseFail::ParseFail(const std::string &name) {
	(void)name;
};

const char* BitcoinExchange::ParseFail::what() const noexcept {
	return this->_message.c_str();
};

// Non-member functions
std::ostream&	operator<<( std::ostream& out, const ymd& date ) {
	out << static_cast<int>(date.year()) << DATE_SEPARATOR
	<< std::setw(2) << std::setfill('0')
	<< static_cast<unsigned int>(date.month()) << DATE_SEPARATOR
	<< std::setw(2) << std::setfill('0')
	<< static_cast<unsigned int>(date.day());
	return out;
};
