/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:36:46 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/18 17:37:49 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

// Calling swap(), min() and max() via ::func() bypasses any local functions
// of the same name and specifies a global one, in this case functions declared
// in the *.hpp file.

int	main(void)
{
	int	a = 2;
	int	b = 3;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

	std::cout << "\n";

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	std::cout << "\n";

	int e = 42;
	int f = 42;
	std::cout << "e address = " << &e << "\n";
	std::cout << "f address = " << &f << "\n";
	std::cout << "min( d, e ) address = " << &::min(e, f) << "\n";
	std::cout << "max( d, e ) address = " << &::max(e, f) << "\n";

	return (0);
}
