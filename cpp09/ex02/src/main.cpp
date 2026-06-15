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
		vecInput = PmergeMe<vector>::loadData(argc + 1);
		std::cout << "VECTOR\n";
		std::cout << "Before: " << vecInput << "\n";
		auto	vecStart = std::chrono::steady_clock::now();
		vecOutput = PmergeMe<vector>::fordJohnsonAlgo(vecInput);
		auto	vecEnd = std::chrono::steady_clock::now();
		std::cout << "After: " << vecOutput << "\n";
		std::cout << "Vector is" << (PmergeMe<vector>::isSort(vecOutput) ? " " : " not ") << "sorted!\n";


		lstInput = PmergeMe<list>::loadData(argc + 1);
		std::cout << "LIST\n";
		std::cout << "Before: " << lstInput << "\n";
		auto	lstStart = std::chrono::steady_clock::now();
		lstOutput = PmergeMe<list>::fordJohnsonAlgo(lstInput);
		auto	lstEnd = std::chrono::steady_clock::now();
		std::cout << "After: " << lstOutput << "\n";
		std::cout << "List is" << (PmergeMe<list>::isSort(lstOutput) ? " " : " not ") << "sorted!\n";


		std::chrono::duration<double>	vecElapsed = vecEnd - vecStart;
		std::chrono::duration<double>	lstElapsed = lstEnd - lstStart;
		std::cout << "RESULTS\n";
		std::cout << "fordJohnsonAlgo() took " << vecElapsed.count()
			<< " seconds to sort a vector! :)\n";
		std::cout << "fordJohnsonAlgo() took " << lstElapsed.count()
			<< " seconds to sort a list! :)\n";
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	return EXIT_SUCCESS;
};
