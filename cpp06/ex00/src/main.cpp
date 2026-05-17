/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:24:25 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/17 18:55:34 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int	main( int argc, char **argv ) {
	if (argc != 2) {
		std::cout << "Usage: './Scalar <argument>\n";
		return 0;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
};
