/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:36:46 by thblack-          #+#    #+#             */
/*   Updated: 2026/06/08 13:21:44 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "PmergeMe.cpp"
#include <iostream> // for std::cout
#include <chrono> // for time measurements

int	main(int argv, char **argc) {
	if (argv < 2) {
		std::cerr << "Error: no input\n"
		<< "Example usage: ./PmergeMe 3 2 1\n";
		return EXIT_FAILURE;
	}
	vector	vecInput, vecOutput;
	list	lstInput, lstOutput;
	try {
		auto	vecStart = std::chrono::steady_clock::now();
		vecInput = PmergeMe<vector>::loadData(argc + 1);
		vecOutput = PmergeMe<vector>::fordJohnsonAlgo(vecInput);
		auto	vecEnd = std::chrono::steady_clock::now();

		auto	lstStart = std::chrono::steady_clock::now();
		lstInput = PmergeMe<list>::loadData(argc + 1);
		lstOutput = PmergeMe<list>::fordJohnsonAlgo(lstInput);
		auto	lstEnd = std::chrono::steady_clock::now();
		std::cout << "Before: " << vecInput << "\n";
		std::cout << "After: " << vecOutput << "\n";

		std::chrono::duration<double>	vecElapsed = vecEnd - vecStart;
		std::chrono::duration<double>	lstElapsed = lstEnd - lstStart;
		std::cout << "Time to process a range of " << vecInput.size()
		<< " elements with std::vector : " << vecElapsed.count() << " seconds\n";
		std::cout << "Time to process a range of " << lstInput.size()
		<< " elements with std::list : " << lstElapsed.count() << " seconds \n";
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}
	return EXIT_SUCCESS;
};
