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
	if (argv != 2) {
		std::cerr << "Error: could not open file\n"
		<< "Usage: ./BitcoinExchange [path_to_input_file]\n";
		return 1;
	}

	BitcoinExchange	exchange("data.csv");
	exchange.evaluateInput(argc[1]);
	// (void)argc;
	// for (auto x: exchange.getDatabase())
	// 	std::cout << x.first << " " << x.second << "\n";
	return 0;
};
