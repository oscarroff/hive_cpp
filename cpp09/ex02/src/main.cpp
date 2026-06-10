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
		vecOutput = PmergeMe<vector>::fordJohnsonAlgo(vecInput);
		std::cout << "VECTOR\n";
		std::cout << "Before: " << vecInput << "\n";
		std::cout << "After: " << vecOutput << "\n";
		lstInput = PmergeMe<list>::loadData(argc + 1);
		lstOutput = PmergeMe<list>::fordJohnsonAlgo(lstInput);
		std::cout << "LIST\n";
		std::cout << "Before: " << lstInput << "\n";
		std::cout << "After: " << lstOutput << "\n";
		// vecInput = PmergeMe::loadVectorData(argc + 1);
		// lstInput = PmergeMe::loadListData(argc + 1);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	std::cout << "I am working!\n";
};
