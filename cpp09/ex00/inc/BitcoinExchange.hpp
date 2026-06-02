/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:48:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/13 10:48:55 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map> // for std::map<typename T1, ...>
#include <ctime> // for time_t

class BitcoinExchange {
private:
    std::map<time_t, int>   _database;
public:
    // Constructors & destructors
    BitcoinExchange() = default;
    BitcoinExchange( const char* path );
    BitcoinExchange( const BitcoinExchange& other );
    BitcoinExchange &operator=( const BitcoinExchange &other );
    ~BitcoinExchange();
    // Public member functions
    std::map<time_t, int>&	getMap();
    void    loadCSV( const char* path );
};
