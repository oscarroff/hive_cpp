/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:36:46 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/19 14:35:30 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <bits/stdc++.h>

int	main(int argv, char **argc) {
	std::cout << "I am working!\n";
	if (argv != 2) {
		std::cout << "Usage: ./BitcoinExchange [path_to_input_file]\n";
		return 0;
	}
	(void)argc;
	BitcoinExchange	exchange("data.csv");
	for (auto x: exchange.getMap())
		std::cout << x.first << " " << x.second << "\n";
	std::cout << "getValue: " << exchange.getValue("2022-03-29") << "\n";
	return 0;
};
