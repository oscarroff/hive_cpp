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

#include "RPN.hpp"
#include <iostream>

int	main(int argv, char **argc) {
	if (argv != 2) {
		std::cerr << "Error: no input\n"
		<< "Example usage: ./RPN \"1 1 +\"\n";
		return 1;
	}
	(void)argc;
	std::cout << "I am working!\n";
	return 0;
};
