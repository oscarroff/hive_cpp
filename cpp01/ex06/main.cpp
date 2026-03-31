/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:06:14 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/25 17:07:14 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstdlib>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc < 2) {
		std::cout << "[ No problems? Really? ]\n";
		return (EXIT_SUCCESS);
	}
	if (argc > 2) {
		std::cout << "[ One problem at a time please... ]\n";
		return (EXIT_SUCCESS);
	}
	Harl	harl;
	harl.filter(argv[1]);
	return (EXIT_SUCCESS);
}
