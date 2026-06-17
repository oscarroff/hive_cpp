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
#include <iostream> // for std::cout && std::cerr

int	main(int argc, char **argv) {
	if (argc != 2) {
		if (argc < 2)
			std::cerr << "Error: no input\n";
		else
			std::cerr << "Error: too many arguments, expects single string input\n";
		std::cerr << "Example usage: ./RPN \"1 1 +\"\n";
		return EXIT_FAILURE;
	}
	try {
		int	result = RPN::calculate(argv[1]);
		std::cout << result << "\n";
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
};
