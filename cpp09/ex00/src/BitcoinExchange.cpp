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
#include <climits>
#include <optional>

std::ostream&	operator<<( std::ostream& out, const ymd& date );

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
	loadDatabase(path);
};

// Public member functions
std::map<ymd, long>&	BitcoinExchange::getDatabase() {
	return this->_database;
};

// Parse a date with a given separator char into a std::chrono::year_month_day value
std::optional<ymd>	BitcoinExchange::parseDate( const std::string& dateString, char separator ) const {
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

// Parse a value of Bitcoin or an amount
// From the example data we see that Bitcoin's value is measured up to 3 decimal places
// Thus this progam in its default setting calculates with a fixed-point decimal with
// 3 decimal places, stored as an int
// Using the more modern std::from_chars which has better performance and easier
// error handling that std::stoi
std::optional<long>	BitcoinExchange::parseValue( const std::string& numString ) const {
	if (!numString.find(floatChars))
		return std::nullopt;

	long	value;
	auto res = std::from_chars(numString.data(),
		numString.data() + numString.find_first_not_of(numberChars), value);
	if (res.ec != std::errc() || value > INT_MAX || value < INT_MIN)
		return std::nullopt;
	value *= decimalFactor;

	std::string	fractionString(res.ptr, numString.data() + numString.size());
	if (fractionString.empty() || fractionString[0] != '.' || !fractionString[1])
		return value;

	int	fraction = 0;
	res = std::from_chars(fractionString.data() + 1,
		fractionString.data() + fractionString.size(), fraction);
	if (res.ec != std::errc())
		return std::nullopt;
	fraction *= std::pow(10, decimalExponent - fractionString.size() + 1);

	value += fraction;
	return value;
}

std::optional<int>	BitcoinExchange::getExchangeRate( const ymd& date ) const {
	for (auto it = this->_database.begin(); it != this->_database.end(); ++it) {
		if (it->first == date)
			return it->second;
		else if (it->first > date)
			return it - 1;
	}
	// auto	it = this->_database.find(date);
	// if (it != this->_database.end())
	// 	return it->second;
	return std::nullopt;
}

static void	throwAndFree( const char* message, std::ifstream& file ) {
	file.close();
	throw std::runtime_error(message);
};

void    BitcoinExchange::loadDatabase( const char* path ) {
	std::ifstream	file(path);
	if (!file.is_open())
		throw std::runtime_error("could not open database file");

	std::string	line;
	std::optional<ymd>	date;
	std::optional<long>	bcValue;
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throwAndFree("invalid header", file);

	while (std::getline(file, line)) {
		date = parseDate(line.substr(0, 10), dateSeparator);
		if (!date.has_value())
			throwAndFree("invalid date", file);
		bcValue = parseValue(line.substr(11));
		if (!bcValue.has_value())
			throwAndFree("invalid value", file);
		this->_database.insert({date.value(), static_cast<int>(bcValue.value())});
	}
	file.close();
};

void	BitcoinExchange::evaluateInput( const char* path ) {
	std::ifstream	file(path);
	if (!file.is_open())
		throw std::runtime_error("could not open input file");

	std::string	line;
	std::optional<ymd>	date;
	std::optional<long>	bcValue;
	std::optional<long> exchangeRate;
	long	bcMax = 1000 * decimalFactor;
	std::getline(file, line);
	if (line != "date | value")
		throwAndFree("invalid header", file);

	while (std::getline(file, line)) {
		date = parseDate(line.substr(0, 10), dateSeparator);
		if (!date.has_value()) {
			std::cerr << "Error: invalid date\n";
			continue;
		}
		if (line.substr(10, 3) != " | ") {
			std::cerr << "Error: bad input => " << line << "\n";
			continue;
		}
		bcValue = parseValue(line.substr(13));
		if (!bcValue.has_value()) {
			std::cerr << "Error: invalid value\n";
			continue;
		}
		if (bcValue.value() < 0) {
			std::cerr << "Error: not a positive number\n";
			continue;
		}
		if (bcValue.value() > bcMax) { 
			std::cerr << "Error: too large a number\n";
			continue;
		}
		exchangeRate = getExchangeRate(date.value());
		if (!exchangeRate.has_value()) {
			std::cerr << "Error: no exchange rate data\n";
			continue;
		}
		std::cout << date.value() << " => "
			<< bcValue.value() * decimalReverseFactor << " = "
			<< bcValue.value() * getExchangeRate(date.value())
			* decimalReverseFactor * decimalReverseFactor << "\n";
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
	out << static_cast<int>(date.year()) << BitcoinExchange::dateSeparator
	<< std::setw(2) << std::setfill('0')
	<< static_cast<unsigned int>(date.month()) << BitcoinExchange::dateSeparator
	<< std::setw(2) << std::setfill('0')
	<< static_cast<unsigned int>(date.day());
	return out;
};
