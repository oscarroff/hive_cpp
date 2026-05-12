/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:24:04 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/12 15:13:29 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main( void )
{
	Bureaucrat	sally("Sally", 1), bob("Bob", 75), rowan("Rowan", 150);
	try {
		sally.upGrade();
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what();
	}
	return 0;
}
