/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:36:46 by thblack-          #+#    #+#             */
/*   Updated: 2026/06/08 11:55:39 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream> // for std::cout

int	main(int argv, char **argc) {
	if (argv != 2) {
		std::cerr << "Error: no input\n"
		<< "Example usage: ./RPN \"1 1 +\"\n";
		return EXIT_FAILURE;
	}
	try {
		std::deque<int>	equation = RPN::parseInput(argc[1]);
		int	result = RPN::calculate(equation);
		std::cout << result << "\n";
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
};
