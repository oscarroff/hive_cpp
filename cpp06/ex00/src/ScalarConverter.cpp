/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:48:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/17 21:06:12 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream> // for std::cout / cerr
#include <limits> // for numeric_limits
#include <stdexcept> // for std::out_of_range
#include <cmath> // for std::modf
#include <iomanip> // for std::setprecision

enum	scalarType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	ERROR,
};

// Forward declarations:
// === Parsing Stage === 
static scalarType	resolveType( const std::string& literal );
static bool			isChar( const std::string& literal );
static bool			isInt( const std::string& literal );
static bool			isFloat( const std::string& literal );
static bool			isDouble( const std::string& literal );
static bool			isNonFinite( const std::string& literal );
// === Conversion Stage ===
static void			literalChar( char c );
static void			convertInt( const std::string& literal );
static void			literalInt( int num );
static void			convertFloat( const std::string& literal );
static void			literalNonFiniteFloat( const std::string& literal );
static void			literalFloat( float num );
static void			convertDouble( const std::string& literal );
static void			literalNonFiniteDouble( const std::string& literal );
static void			literalDouble( double num );

// Destructor
ScalarConverter::~ScalarConverter() {};

// === Parsing Stage ===

void	ScalarConverter::convert( const std::string& literal ) {
	switch (resolveType(literal)) {
		case CHAR:
			literalChar(literal.at(0));
			break;
		case INT:
			convertInt(literal);
			break;
		case FLOAT:
			convertFloat(literal);
			break;
		case DOUBLE:
			convertDouble(literal);
			break;
		case ERROR:
			std::cerr << "I don't know about that type!\n";
	};
};

static scalarType	resolveType( const std::string& literal ) {
	if (isChar(literal))
		return CHAR;
	if (isInt(literal))
		return INT;
	if (isFloat(literal))
		return FLOAT;
	if (isDouble(literal))
		return DOUBLE;
	return ERROR;
};

static bool	isChar( const std::string& literal ) {
	if (literal.length() != 1)
		return false;
	if (literal.at(0) < std::numeric_limits<char>::min()
		|| literal.at(0) > std::numeric_limits<char>::max()
		|| std::isdigit(literal.at(0)))
		return false;
	return true;
};

static bool	isInt( const std::string& literal ) {
	for (size_t	i = literal.at(0) == '-' ? 1 : 0; i < literal.length(); i++) {
		if (!std::isdigit(literal.at(i)))
			return false;
	}
	return true;
};

static bool	isFloat( const std::string& literal ) {
	bool	point = false;

	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return true;
	if (literal.at(literal.length() - 1) != 'f')
		return false;
	for (size_t	i = literal.at(0) == '-' ? 1 : 0; i < literal.length() - 1; i++) {
		if (!std::isdigit(literal.at(i)) && literal.at(i) != '.')
			return false;
		if (literal.at(i) == '.') {
			if (point == true)
				return false;
			else
				point = true;
		}
	}
	return true;
};

static bool	isDouble( const std::string& literal ) {
	bool	point = false;

	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return true;
	for (size_t	i = literal.at(0) == '-' ? 1 : 0; i < literal.length(); i++) {
		if (!std::isdigit(literal.at(i)) && literal.at(i) != '.')
			return false;
		if (literal.at(i) == '.') {
			if (point == true)
				return false;
			else
				point = true;
		}
	}
	return true;
};

static bool isNonFinite( const std::string& literal ) {
	if (literal == "nan" || literal == "nanf" || literal == "-inf"
		|| literal == "-inff" || literal == "+inf" || literal == "+inff")
		return true;
	return false;
};

// === Converstion Stage ===
// === CHAR ===

static void	literalChar( char c ) {
	std::cout << "char: '" << c << "'\n"
		<< "int: " << static_cast<int>(c) << "\n"
		<< "float: " << static_cast<float>(c) << ".0f\n"
		<< "double: " << static_cast<double>(c) << ".0\n";
};

// === INT ===

static void	convertInt( const std::string& literal ) {
	try {
		int res = std::stoi(literal);
		literalInt(res);
	}
	catch (const std::out_of_range& e) {
		std::cerr << "int conversion fail: out of range\n";
	}
};

static void	literalInt( int num ) {
	std::cout << "char: ";
	if (!std::isprint(num))
		std::cout << "non displayable\n";
	else
		std::cout << "'" << static_cast<char>(num) << "'\n";
	std::cout << "int: " << num << "\n"
		<< "float: " << static_cast<float>(num) << ".0f\n"
		<< "double: " << static_cast<double>(num) << ".0\n";
};

// === FLOAT ===

static void	convertFloat( const std::string& literal ) {
	if (isNonFinite(literal)) {
		literalNonFiniteFloat(literal);
		return ;
	}
	try {
		float res = std::stof(literal);
		literalFloat(res);
	}
	catch (const std::out_of_range& e) {
		std::cout << "float conversion fail: out of range\n";
	}
};

static void	literalNonFiniteFloat( const std::string& literal ) {
	std::cout << "char: impossible\n"
		<< "int: impossible\n"
		<< "float: " << literal << "\n"
		<< "double: " << literal.substr(0, literal.size() - 1) << "\n";
};

static void	literalFloat( float num ) {
	// CHAR
	std::cout << "char: ";
	// Check that number is finite, that is not fractional and that it is
	// displayable
	float i;
	if (!std::isfinite(num) || std::modf(num, &i) != 0.0f
		|| num < 32.0f || num > 126.0f)
		std::cout << "non displayable\n";
	else
		std::cout << "'" << static_cast<char>(num) << "'\n";

	// INT
	// Check number is within integer limits
	std::cout << "int: ";
	if (num < static_cast<float>(std::numeric_limits<int>::min())
		|| num > static_cast<float>(std::numeric_limits<int>::max()))
		std::cout << "out of range\n";
	else
		std::cout << static_cast<int>(num) << "\n";

	// FLOAT
	bool	isIntegerValue = std::modf(num, &i) == 0.0f ? true : false;
	std::cout << "float: "
		// Set precision to maximum number of significant digits
		<< std::defaultfloat
		<< std::setprecision(std::numeric_limits<float>::max_digits10)
		<< num;
	// Check number is integer
	if (isIntegerValue)
		std::cout << ".0";
	// Add float formating
	std::cout << "f\n";

	// DOUBLE
	std::cout << "double: "
		// Set precision to maximum number of significant digits
		<< std::defaultfloat
		<< std::setprecision(std::numeric_limits<double>::max_digits10)
		<< static_cast<double>(num);
	// Check number is integer
	if (isIntegerValue)
		std::cout << ".0";
	std::cout << "\n";
};

// === FLOAT ===

static void	convertDouble( const std::string& literal ) {
	if (isNonFinite(literal)) {
		literalNonFiniteDouble(literal);
		return ;
	}
	try {
		double res = std::stod(literal);
		literalDouble(res);
	}
	catch (const std::out_of_range& e) {
		std::cerr << "double conversion fail: out of range\n";
	}
};

static void	literalNonFiniteDouble( const std::string& literal ) {
	std::cout << "char: impossible\n"
		<< "int: impossible\n"
		<< "float: " << literal << "f\n"
		<< "double: " << literal << "\n";
};

static void	literalDouble( double num ) {
	// CHAR
	std::cout << "char: ";
	// Check that number is finite, that is not fractional and that it is
	// displayable
	double i;
	if (!std::isfinite(num) || std::modf(num, &i) != 0.0
		|| num < 32.0 || num > 126.0)
		std::cout << "non displayable\n";
	else
		std::cout << "'" << static_cast<char>(num) << "'\n";

	// INT
	// Check number is within integer limits
	std::cout << "int: ";
	if (num < static_cast<double>(std::numeric_limits<int>::min())
		|| num > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "out of range\n";
	else
		std::cout << static_cast<int>(num) << "\n";

	// FLOAT
	// Check number is within float limits
	std::cout << "float: ";
	if (num < static_cast<double>(std::numeric_limits<float>::lowest())
		|| num > static_cast<double>(std::numeric_limits<float>::max()))
		std::cout << "out of range\n";
	else {
		// Set precision to maximum number of significant digits
		std::cout << std::defaultfloat
			<< std::setprecision(std::numeric_limits<float>::max_digits10)
			<< static_cast<float>(num);
		// Check number is integer if cast as float
		float j;
		if (std::modf(static_cast<float>(num), &j) == 0.0f)
			std::cout << ".0";
		// Add float formating
		std::cout << "f\n";
	}

	// DOUBLE
	std::cout << "double: "
		// Set precision to maximum number of significant digits
		<< std::defaultfloat
		<< std::setprecision(std::numeric_limits<double>::max_digits10)
		<< num;
	// Check number is integer as original double value
	if (std::modf(num, &i) == 0.0)
		std::cout << ".0";
	std::cout << "\n";
};
