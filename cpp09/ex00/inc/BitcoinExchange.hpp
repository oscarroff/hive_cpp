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
#include <chrono>
#include <map>   // for std::map<typename T1, ...>
#include <string>

// DECIMAL_FACTOR
// We want to preserve accuracy for 2 decimal places, thus ints holding the
// value of the bitcoin are handled as: stored value = original value * 10^2
#define DECIMAL_FACTOR 100

using ymd = std::chrono::year_month_day;

class BitcoinExchange {
private:
	std::map<ymd, int> _database;
public:
	// Constructors & destructors
	BitcoinExchange() = default;
	BitcoinExchange(const char *path);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();
	// Public member functions
	std::map<ymd, int> &getMap();
	void loadCSV(const char *path);
	int	getValue( const std::string& dateString ) const;

	// Custom Exceptions
	class ParseFail : public std::exception {
	private:
		std::string _message;
	public:
		ParseFail(const std::string &name);
		const char *what() const noexcept override;
	};
};
