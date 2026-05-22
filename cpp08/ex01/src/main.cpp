/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:36:46 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/20 09:12:24 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int	main(void) {
	unsigned int	longest;
	unsigned int	shortest;

	std::cout << "=== Small span of 10 ===\n";
	Span	span1(10);
	for (int i = 1; i < 11; i++) {
		try {
			span1.addNumber(i);
		}
		catch (std::exception& e) {
			std::cerr << "Exception: " << e.what() << "\n";
		}
	}
	std::cout << span1 << "\n";
	try {
		longest = span1.longestSpan();
		std::cout << "Longest span is " << longest << "\n";
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}
	try {
		shortest = span1.shortestSpan();
		std::cout << "Shortest span is " << shortest << "\n";
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}
	std::cout << "\n";

	std::cout << "=== Big spans ===\n";
	Span	span2(100);
	try {
		span2.addRange(0, 1, 101);
		std::cout << span2 << "\n";
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}
	std::cout << "\n";

	Span	span3(100);
	try {
		span3.addRange(0, 1, 100);
		std::cout << "span3: " << span3 << "\n";
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}
	try {
		longest = span3.longestSpan();
		std::cout << "Longest span is " << longest << "\n";
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}
	try {
		shortest = span3.shortestSpan();
		std::cout << "Shortest span is " << shortest << "\n";
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}
	std::cout << "\n";

	Span	span4(100);
	try {
		span4.addRange(0, 50, -49);
		std::cout << "span4: " << span4 << "\n";
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}
	try {
		longest = span4.longestSpan();
		std::cout << "Longest span is " << longest << "\n";
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}
	try {
		shortest = span4.shortestSpan();
		std::cout << "Shortest span is " << shortest << "\n";
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}
	std::cout << "\n";

	std::cout << "=== Really big spans ===\n";
	Span	span5(100000);
	try {
		span5.addRange(0, 1, 100000);
		std::cout << "span3: " << span5 << "\n";
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}
	try {
		longest = span5.longestSpan();
		std::cout << "Longest span is " << longest << "\n";
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}
	try {
		shortest = span5.shortestSpan();
		std::cout << "Shortest span is " << shortest << "\n";
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}
	std::cout << "\n";

	return 0;
};
