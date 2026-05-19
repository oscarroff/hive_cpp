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

#include "easyfind.tpp"
#include <iostream>
#include <array>
#include <vector>
#include <deque>

int	main(void) {
	std::cout << "=== array tests ===\n";
	std::vector<int>	vec1 = {1, 2, 3, 4};
	auto	it1 = easyfind(vec1, 2);
	if (it1 != vec1.end())
		std::cout << "2 was found at index: "
			<< std::distance(vec1.begin(), it1) << "\n";
	else
		std::cout << "2 was not found!\n";
	it1 = easyfind(vec1, 42);
	if (it1 != vec1.end())
		std::cout << "42 was found at index: "
			<< std::distance(vec1.begin(), it1) << "\n";
	else
		std::cout << "42 was not found!\n";
	std::cout << "\n";

	std::cout << "=== array tests ===\n";
	std::array<int, 4>	arr2 = {1, 2, 3, 4};
	auto	it2 = easyfind(arr2, 2);
	if (it2 != arr2.end())
		std::cout << "2 was found at index: "
			<< std::distance(arr2.begin(), it2) << "\n";
	else
		std::cout << "2 was not found!\n";
	it2 = easyfind(arr2, 42);
	if (it2 != arr2.end())
		std::cout << "42 was found at index: "
			<< std::distance(arr2.begin(), it2) << "\n";
	else
		std::cout << "42 was not found!\n";
	std::cout << "\n";

	std::cout << "=== deque tests ===\n";
	std::deque<int>	deq3 = {1, 2, 3, 4};
	auto	it3 = easyfind(deq3, 2);
	if (it3 != deq3.end())
		std::cout << "2 was found at index: "
			<< std::distance(deq3.begin(), it3) << "\n";
	else
		std::cout << "2 was not found!\n";
	it3 = easyfind(deq3, 42);
	if (it3 != deq3.end())
		std::cout << "42 was found at index: "
			<< std::distance(deq3.begin(), it3) << "\n";
	else
		std::cout << "42 was not found!\n";
	std::cout << "\n";
	return (0);
}
