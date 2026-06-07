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
		std::cerr << "Error: could not open input file\n"
		<< "Usage: ./BitcoinExchange [path_to_input_file]\n";
		return 1;
	}
	try {
		BitcoinExchange	exchange("data.csv");
		exchange.evaluateInput(argc[1]);
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}
	return 0;
};
