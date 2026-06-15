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
#include <cstdlib>
#include <iostream> // for std::cout

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
		if (!PmergeMe<vector>::isSort(vecInput))
			vecOutput = PmergeMe<vector>::fordJohnsonAlgo(vecInput);
		else
			vecOutput = vecInput;
		std::cout << "VECTOR\n";
		std::cout << "Before: " << vecInput << "\n";
		std::cout << "After: " << vecOutput << "\n";
		std::cout << "Result is" << (PmergeMe<vector>::isSort(vecOutput) ? " " : " not ") << "sorted!\n";
		lstInput = PmergeMe<list>::loadData(argc + 1);
		lstOutput = PmergeMe<list>::fordJohnsonAlgo(lstInput);
		std::cout << "LIST\n";
		std::cout << "Before: " << lstInput << "\n";
		std::cout << "After: " << lstOutput << "\n";
		std::cout << "Result is" << (PmergeMe<list>::isSort(lstOutput) ? " " : " not ") << "sorted!\n";
		// vecInput = PmergeMe::loadVectorData(argc + 1);
		// lstInput = PmergeMe::loadListData(argc + 1);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	return EXIT_SUCCESS;
};
