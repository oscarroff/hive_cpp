/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:48:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/06/03 10:22:59 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ctime> // for time_t
#include <chrono> // for std::chrono
#include <map>   // for std::map<typename T1, ...>
#include <optional> // for std::optional<typename T>

// Template struct to allow compile time caluculation of the decimal factor
// with an overload for when the exponent is zero i.e. result = 1
template<int B, int E>
struct Power {
	static constexpr int	value = B * Power<B, E - 1>::value;
};
template<int B>
struct Power<B, 0> {
	static constexpr int	value = 1;
};

// Struct for the fixed point type
struct	fixed;

using ymd = std::chrono::year_month_day;

class BitcoinExchange {
private:
	std::map<ymd, fixed>	_database;
	std::optional<fixed>	parseValue( const std::string& numString ) const;
	std::optional<ymd>		parseDate( const std::string& dateString, char delimiter ) const;
public:
	// Constructors & destructors
	BitcoinExchange() = default;
	BitcoinExchange(const char *path);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();
	// Public member functions
	std::map<ymd, fixed>	&getDatabase();
	void					loadDatabase(const char *path);
	void					evaluateInput( const char* path );
	std::optional<fixed>	getExchangeRate( const ymd& date ) const;

	// Static Member Variables
	// We want to preserve accuracy for 3 decimal places, thus ints holding the
	// value of the bitcoin are handled as: stored value = original value * 10^3
	// Suggested range for this variable is 0-5 depending on application

	// ========== decimalExponent ==========
	// adjust for fixed point accuracy
	static constexpr int			decimalExponent = 3;
	// all other values below will scale to this value
	// =====================================

	static constexpr int			decimalFactor = Power<10, decimalExponent>::value;
	static constexpr long			bitcoinMax = 1000 * decimalFactor;
	// Separator to be used when writing the date e.g. 2026-05-31
	static constexpr char			dateDelimiter = '-';
	static constexpr char			databaseSeparator = ',';
	static constexpr const char*	inputSeparator = " | ";
	static constexpr const char*	digitChars = "0123456789";
	static constexpr const char*	ymdChars = "0123456789-";
	static constexpr const char*	numberChars = "0123456789+-";
	static constexpr const char*	floatChars = "0123456789+-.";
};

std::ostream&	operator<<( std::ostream& out, const ymd& date );
