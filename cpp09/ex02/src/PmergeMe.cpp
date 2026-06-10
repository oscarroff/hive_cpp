/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:48:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/06/08 13:18:54 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <charconv> // for std::from_chars
#include <cstring> // for std::strlen
#include <stdexcept> // for std::runtime_error
#include <iostream>

template <typename T>
T	PmergeMe<T>::loadData( char** args ) {
	unsigned int			value;
	std::from_chars_result	flag;
	T						result;
	while (*args != nullptr) {
		flag = std::from_chars(*args, *args + std::strlen(*args), value);
		if (flag.ec != std::errc())
			throw std::runtime_error("integer conversion fail");
		result.push_back(value);
		args++;
	}
	return result;
};

// Sorting of pairs done simply with std::swap_range()
template <typename T>
static void	sortPairRange( T& data, size_t position, size_t pairSize ) {
	size_t	elementSize = pairSize / 2;
	auto	pair1last = std::next(data.begin(), position + elementSize - 1);
	auto	pair2last = std::next(data.begin(), position + (pairSize) - 1);
	if (*pair1last < *pair2last)
		return;
	auto	pair1first = std::next(data.begin(), position);
	auto	pair2first = std::next(data.begin(), position + elementSize);
	std::swap_ranges(pair1first, pair2first, pair2first); 
};

// Builds arrays of iterators for main and pend
// Unsure about where to place b1, into main or pend
template <typename T>
static void	buildChains( T& main, T& pend, size_t elementSize ) {
	bool	pendToggle = true;
	size_t	i = 2 * elementSize;
	while (i + elementSize - 1 < main.size()) {
		if (pendToggle == true) {
			auto	elementBegin = std::next(main.begin(), i - pend.size());
			auto	elementLast = std::next(main.begin(), i + elementSize - pend.size() - 1);
			auto	elementEnd = std::next(main.begin(), i + elementSize - pend.size());
			pend.insert(pend.end(), elementBegin, elementEnd);
			main.erase(elementBegin, elementLast);
		}
		else
			i += elementSize;
		pendToggle = !pendToggle;
	}
};

// Finds position in main for position in pend of elementSize
// 1. lower and upper limits are gradually narrowed until position found
// 2. insert() and erase() called on data to move range of data
template <typename T>
static void	resolveInsertion( T& main, T& pend,
							 size_t i, size_t jacobsPrevious, size_t elementSize ) {
	auto	lower = main.begin();
	auto	upper = std::next(main.begin(), (jacobsPrevious * 2) + i - 1);
	auto	middle = std::next(main.begin(), std::distance(lower, upper) / 2);
	auto	pendBegin = std::next(pend.begin(), i);
	auto	pendCompValue = std::next(pend.begin(), elementSize - 1);
	auto	pendEnd = std::next(pend.begin(), elementSize);
	while (1) {
		if (lower == upper) {
			if (*pendCompValue < *lower)
				main.insert(lower, pendBegin, pendEnd);
			else
				main.insert(std::next(lower, 1), pendBegin, pendEnd);
			pend.erase(pendBegin, pendCompValue);
			// data.erase(iters[1][i], std::next(iters[1][i], elementSize - 1));
			break;
		}
		if (*pendCompValue < *middle)
			lower = middle - 1;
		else
			upper = middle + 1;
		middle = std::next(main.begin(), std::distance(lower, upper) / 2);;
	}
};

// Function calculates next value of Jacobsthal sequence
// Jn+1 = 2Jn + (-1)^n
static void	nextJacobsthal( size_t& previousValue, size_t& currentValue, size_t& currentN) {
	size_t	temp = currentValue;
	currentValue = 2 * currentValue + currentN % 2 ? -1 : 1;
	previousValue = temp;
	++currentN;
};

// Merge insertion loop
// 1. keeps track of Jacobsthal sequence
// 2. jumps forward to next nth of sequence
// 3. finds nth value in the pend
// 4. calls resolveInsertion() on that value 
// 5. exits when the range between n-1 and n of Jacobsthal fall outside pend size
template <typename T>
static void	mergeInsert( T& main, T& pend, size_t elementSize ) {
	size_t	jacobsPrevious = 1, jacobsCurrent = 3, jacobsN = 3;
	size_t	i = jacobsCurrent - jacobsPrevious - 1;
	while (!pend.empty()) {
		// Passing jacobsPrevious here in effect passes the number that is already
		// sorted
		resolveInsertion(main, pend, i, jacobsPrevious, elementSize);
		if (i > 0)
			--i;
		else {
			nextJacobsthal(jacobsPrevious, jacobsCurrent, jacobsN);
			i = jacobsCurrent - jacobsPrevious - 1;
			if (i > pend.size() - 1)
				i = pend.size() - 1;
		}
	}
};

// Main algorithm
// 1. calls sortPairRange() to do the initial sort of pairs up to max size of
//    totalSize / pairSize > 0
// 2. goes into main merge loop starting with largest pairSize decreasing to smallest
// 3. builds the main and pend chains as arrays of iterator pointers
// 4. calls mergeInsert()
// 5. returns sorted data
template <typename T>
T	PmergeMe<T>::fordJohnsonAlgo( const T& data ) {
	T		main(data);
	size_t	pairSize = 2;
	while (main.size() / pairSize > 0) {
		for (size_t i = 0; main.size() - i >= pairSize && i < main.size(); i += pairSize)
			sortPairRange(main, i, pairSize);
		pairSize *= 2;
	}
	if (main.size() < 3)
		return main;
	T	pend;
	size_t	elementSize = pairSize;
	while (main.size() / elementSize < 3)
		elementSize /= 2;
	while (elementSize > 0) {
		std::cout << "pairSize: " << elementSize << "\n";
		buildChains(main, pend, elementSize);
		std::cout << "main\n";
		for (auto it = main.begin(); it != main.end(); it = std::next(it)) {
			std::cout << "i: " << *it << "\n";
		}
		std::cout << "pend\n";
		for (auto it = pend.begin(); it != pend.end(); it = std::next(it)) {
			std::cout << "i: " << *it << "\n";
		}
		// mergeInsert(main, pend, elementSize);
		elementSize /= 2;
	}
	return main;
};

std::ostream&	operator<<( std::ostream& out, const vector& in ) {
	std::string	str;
	for (auto it = in.begin(); it != in.end(); ++it) {
		str.append(std::to_string(*it) + " ");
	}
	str.pop_back();
	out << str;
	return out;
};

std::ostream&	operator<<( std::ostream& out, const list& in ) {
	std::string	str;
	for (auto it = in.begin(); it != in.end(); ++it) {
		str.append(std::to_string(*it) + " ");
	}
	if (!str.empty())
		str.pop_back();
	out << str;
	return out;
};

// template <typename T>
// vector	PmergeMe<T>::loadVectorData( char** args ) {
// 	unsigned int			value;
// 	std::from_chars_result	flag;
// 	vector					result;
// 	while (*args != nullptr) {
// 		flag = std::from_chars(*args, *args + std::strlen(*args), value);
// 		if (flag.ec != std::errc())
// 			throw std::runtime_error("integer conversion fail");
// 		result.push_back(value);
// 		args++;
// 	}
// 	return result;
// };
//
// template <typename T>
// list	PmergeMe<T>::loadListData( char** args ) {
// 	unsigned int			value;
// 	std::from_chars_result	flag;
// 	list					result;
// 	while (*args != nullptr) {
// 		flag = std::from_chars(*args, *args + std::strlen(*args), value);
// 		if (flag.ec != std::errc())
// 			throw std::runtime_error("integer conversion fail");
// 		result.push_back(value);
// 		args++;
// 	}
// 	return result;
// };

// Print for iters
// std::cout << "main\n";
// for (size_t i = 0; i < iters[0].size(); ++i) {
// 	std::cout << "i: " << std::distance(result.begin(), iters[0][i]) << "\n";
// }
// std::cout << "pend\n";
// for (size_t i = 0; i < iters[1].size(); ++i) {
// 	std::cout << "i: " << std::distance(result.begin(), iters[1][i]) << "\n";
// }

// Old mergeInsert
// template <typename T>
// static void	mergeInsert( T& data, chain<T>* iters, size_t elementSize ) {
// 	if (data.size() < 3) 
// 		return;
// 	size_t	jacobsPrevious = 1, jacobsCurrent = 3, jacobsN = 3;
// 	size_t	i = jacobsCurrent - 1;
// 	while (1) {
// 		if (i > jacobsPrevious - 1) {
// 			if (i < iters[1].size())
// 				resolveInsertion(data, iters, i, elementSize, jacobsPrevious - 1);
// 			--i;
// 			continue;
// 		}
// 		else {
// 			nextJacobsthal(jacobsPrevious, jacobsCurrent, jacobsN);
// 			if (jacobsPrevious >= iters[1].size())
// 				break;
// 			i = jacobsCurrent - 1;
// 		}
// 	}
// };

// Old buildChains()
// template <typename T>
// static chain<T>	*buildChains( T& data, size_t elementSize ) {
// 	chain<T>	*iters = new chain<T>[2];
// 	auto it = data.begin();
// 	iters[0].push_back(it);
// 	iters[1].push_back(it);
// 	it = std::next(it, elementSize);
// 	bool	mainPendToggle = true;
// 	while (1) {
// 		if (mainPendToggle == true)
// 			iters[0].push_back(it);
// 		else
// 			iters[1].push_back(it);
// 		if (abs(std::distance(it, data.end())) <= elementSize)
// 			break;
// 		mainPendToggle = !mainPendToggle;
// 		it = std::next(it, elementSize);
// 	}
// 	return iters;
// };

// static size_t	nJacobsthal( size_t nth ) {
// 	size_t	n2 = 1, n1 = 1, n0 = 3, temp;
// 	while (nth > n0) {
// 		temp = n0;
// 		n0 = n2 * 2 + n1;
// 		n2 = n1;
// 		n1 = temp;
// 	}
// 	return n0;
// };

// Old resolveInsertion
// template <typename T>
// static void	resolveInsertion( T& data, chain<T>* iters,
// 							 size_t i, size_t elementSize, size_t sortedPend ) {
// 	size_t	lower = 0, upper = i - 1, middle;
// 	while (1) {
// 		if (lower == upper) {
// 			if (iters[1][i] > iters[0][lower])
// 				data.insert(iters[0][lower + 1], iters[1][i], std::next(iters[1][i], elementSize - 1));
// 			else
// 				data.insert(iters[0][lower], iters[1][i], std::next(iters[1][i], elementSize - 1));
// 			data.erase(iters[1][i], std::next(iters[1][i], elementSize - 1));
// 			break;
// 		}
// 		middle = (upper - lower) / 2;
// 		if (iters[1][i] > iters[0][middle / 2])
// 			lower = middle + 1;
// 		else
// 			upper = middle - 1;
// 	}
// 	(void)sortedPend;
// };
