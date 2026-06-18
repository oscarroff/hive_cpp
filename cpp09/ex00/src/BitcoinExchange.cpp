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
#include <charconv>
#include <climits>
#include <sstream>

// Forward overload declarations
std::ostream&	operator<<( std::ostream& out, const ymd& date );
std::ostream&	operator<<( std::ostream& out, const fixed& f );

// Struct for the fixed point type
struct	fixed {
	long	n;
	fixed(long v = 0) : n(v) {}
	operator long() const { return n; }
};

// ========== OCF ==========

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

// ========== Public member functions ==========

// Getter for the bitcoin database
std::map<ymd, fixed>&	BitcoinExchange::getDatabase() {
	return this->_database;
};

// Parse a date with a given separator char into a std::chrono::year_month_day value
std::optional<ymd>	BitcoinExchange::parseDate( const std::string& dateString, char delimiter ) const {
	int		year, month, day;
	char	s1, s2;
	std::stringstream	ss(dateString);
	if (!(ss >> year >> s1 >> month >> s2 >> day) ||
		s1 != delimiter || s2 != delimiter)
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
std::optional<fixed>	BitcoinExchange::parseValue( const std::string& numString ) const {
	if (!numString.find(floatChars))
		return std::nullopt;

	fixed	result;
	long	value;
	auto res = std::from_chars(numString.data(),
		numString.data() + numString.find_first_not_of(numberChars), value);
	// std::from_chars_result res = std::from_chars(numString.data(),
	// 	numString.data() + numString.find_first_not_of(numberChars), value);
	if (res.ec != std::errc())
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
	result.n = value;
	return result;
}

// Getter for the exchange rate, returns if a match or if there is an earlier date
std::optional<fixed>	BitcoinExchange::getExchangeRate( const ymd& date ) const {
	auto it = this->_database.begin();
	if (date < it->first)
		return std::nullopt;
	while (it != this->_database.end()) {
		if (it->first == date)
			return it->second;
		else if (it->first > date) {
			--it;
			return it->second;
		}
		++it;
	}
	--it;
	if (date > it->first)
		return it->second;
	return std::nullopt;
}

// Helper function for throwing an error and closing the file stream
static void	throwAndFree( const char* message, std::ifstream& file ) {
	file.close();
	throw std::runtime_error(message);
};

// Load a database file e.g. 'data.csv' into the database map of the object
// Is called by a specialist constructor overload
void    BitcoinExchange::loadDatabase( const char* path ) {
	std::ifstream	file(path);
	if (!file.is_open())
		throw std::runtime_error("could not open database file");

	std::string	line;
	size_t		position;
	std::optional<ymd>		date;
	std::optional<fixed>	bitcoin;
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throwAndFree("invalid header", file);

	while (std::getline(file, line)) {
		position = line.find_first_of(databaseSeparator);
		date = parseDate(line.substr(0, position), dateDelimiter);
		if (!date.has_value())
			throwAndFree("invalid date", file);
		bitcoin = parseValue(line.substr(11));
		if (!bitcoin.has_value())
			throwAndFree("invalid value", file);
		this->_database.insert({date.value(), bitcoin.value()});
	}
	file.close();
};

// Safe multiplication by manually checking for overflow in each case
// i.e. left & right large, left & right small, or left & right opposite signs
static bool	safeMultiply( long& result, long left, long right ) {
	result = 0;
	if (left == 0 || right == 0)
		return true;
	if (left > 0 && right > 0) {
		if (left > LLONG_MAX / right)
			return false;
	} else if (left < 0 && right < 0) {
		if (left < LLONG_MAX / right)
		return false;
	} else {
		if (left < 0 && right > 0) {
			if (left < LLONG_MAX / right)
				return false;
		} else {
			if (right < LLONG_MAX / left)
				return false;
		}
	}
	result = left * right;
	return true;
}

// Takes in a path to an input file, parses the data and checks for
// values in the database
void	BitcoinExchange::evaluateInput( const char* path ) {
	std::ifstream	file(path);
	if (!file.is_open())
		throw std::runtime_error("could not open input file");

	std::string	line;
	size_t	position;
	size_t	separatorLength = std::strlen(inputSeparator);
	std::optional<ymd>		date;
	std::optional<fixed>	bitcoin, exchangeRate;
	fixed	result;
	std::getline(file, line);
	if (line != "date | value")
		throwAndFree("invalid header", file);

	while (std::getline(file, line)) {
		position = line.find_first_of(' ');
		if (position == std::string::npos
			|| line.substr(position).length() < separatorLength + 1
			|| line.substr(position, separatorLength) != inputSeparator
			|| !line.find(floatChars, position + separatorLength, 1)
			|| line.find_first_not_of(floatChars, position + separatorLength) != std::string::npos) {
			std::cerr << "Error: bad input => " << line << "\n";
			continue;
		}
		date = parseDate(line.substr(0, position), dateDelimiter);
		if (!date.has_value()) {
			std::cerr << "Error: invalid date\n";
			continue;
		}
		bitcoin = parseValue(line.substr(position + separatorLength));
		if (!bitcoin.has_value()) {
			std::cerr << "Error: invalid value\n";
			continue;
		}
		if (bitcoin.value().n < 0) {
			std::cerr << "Error: not a positive number\n";
			continue;
		}
		if (bitcoin.value().n > bitcoinMax) { 
			std::cerr << "Error: too large a number\n";
			continue;
		}
		exchangeRate = getExchangeRate(date.value());
		if (!exchangeRate.has_value()) {
			std::cerr << "Error: no exchange rate data\n";
			continue;
		}
		if (!safeMultiply(result.n, bitcoin.value().n, exchangeRate.value().n)) {
			std::cerr << "Error: too large a number\n";
			continue;
		}
		result.n /= decimalFactor;
		std::cout << date.value() << " => "
			<< bitcoin.value() << " = "
			<< result << "\n";
	}
	file.close();
};

// ========== Non-member functions ==========

// Overload for cout << for displaying dates with the static member variable delimeter
std::ostream&	operator<<( std::ostream& out, const ymd& date ) {
	out << static_cast<int>(date.year()) << BitcoinExchange::dateDelimiter
	<< std::setw(2) << std::setfill('0')
	<< static_cast<unsigned int>(date.month()) << BitcoinExchange::dateDelimiter
	<< std::setw(2) << std::setfill('0')
	<< static_cast<unsigned int>(date.day());
	return out;
};

// Overload for cout << for displaying the custom fixed point type
std::ostream&	operator<<( std::ostream& out, const fixed& f ) {
	if (f.n % BitcoinExchange::decimalFactor < 1)
		return out << f.n / BitcoinExchange::decimalFactor;
	std::string	os = std::to_string(f.n / BitcoinExchange::decimalFactor)
	+ '.' + std::to_string(f.n % BitcoinExchange::decimalFactor);
	while (!os.empty() && os.back() == '0')
		os.pop_back();
	out << os;
	return out;
};
