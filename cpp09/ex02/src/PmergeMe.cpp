/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:48:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/06/11 16:51:16 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <charconv> // for std::from_chars
#include <cstring> // for std::strlen
#include <stdexcept> // for std::runtime_error
#include <cmath> // for pow()

// Steady clock to measure durations
// for testing: ./PmergeMe `shuf -i 1-1000 -n 3000 | tr "\n" " "`

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

template <typename T>
bool	PmergeMe<T>::isSort( T& data ) {
	if (data.size() < 2)
		return true;
	auto	itA = data.begin(), itB = std::next(data.begin(), 1);
	while (itB != data.end()) {
		if (*itA > *itB)
			return false;
		itA = std::next(itA);
		itB = std::next(itB);
	}
	return true;
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
			auto	elementBegin = std::next(main.begin(), i);
			auto	elementEnd = std::next(main.begin(), i + elementSize);
			pend.insert(pend.end(), elementBegin, elementEnd);
			main.erase(elementBegin, elementEnd);
		}
		else
			i += elementSize;
		pendToggle = !pendToggle;
	}
};

static size_t	roundToScale( size_t value, size_t scale ) {
	return (value / scale) * scale;
}

// Finds position in main for position in pend of elementSize
// 1. lower and upper limits are gradually narrowed until position found
// 2. insert() and erase() called on data to move range of data
// 3. return the updated sorted count
template <typename T>
static void	resolveInsertion( T& main, T& pend, size_t i, size_t treeSize, size_t elementSize ) {
	auto	lower = std::next(main.begin(), elementSize - 1);
	auto	upper = std::next(main.begin(), (treeSize * elementSize) - 1);
	auto	pendBegin = std::next(pend.begin(), i * elementSize);
	auto	pendCompValue = std::next(pendBegin, elementSize - 1);
	auto	pendEnd = std::next(pendBegin, elementSize);
	while (lower != upper) {
		auto middle = std::next(lower, roundToScale(std::distance(lower, upper) / 2, elementSize));
		if (*pendCompValue < *middle) {
			if (lower == middle)
				upper = lower;
			else
				upper = std::next(middle, -elementSize);
		}
		else
			lower = std::next(middle, elementSize);
	}
	if (*pendCompValue < *lower)
		main.insert(std::next(lower, 1 - elementSize), pendBegin, pendEnd);
	else
		main.insert(std::next(lower, 1), pendBegin, pendEnd);
	pend.erase(pendBegin, pendEnd);
};

// Function calculates next value of Jacobsthal sequence
// Jn+1 = 2Jn + (-1)^n
static void	nextJacobsthal( size_t& previousValue, size_t& currentValue, size_t& currentN) {
	size_t	temp = currentValue;
	currentValue = 2 * currentValue + ((currentN % 2) ? -1 : 1);
	previousValue = temp;
	++currentN;
};

static size_t	fetchTreeSize( size_t jN, size_t jC, size_t jP, size_t pS, size_t eS ) {
	size_t	maxTreeSize = pow(2, jN - 1) - 1;
	size_t	treeSize = maxTreeSize - jC + jP
		+ (pS / eS);
	if (treeSize > maxTreeSize)
		treeSize = maxTreeSize;
	return treeSize;
};

// Merge insertion loop
// N.B. j stands for Jacobsthal number
// 1. keeps track of Jacobsthal sequence
// 2. jumps forward to next nth of sequence
// 3. finds nth value in the pend
// 4. calls resolveInsertion() on that value 
// 5. exits when the range between n-1 and n of Jacobsthal fall outside pend size
template <typename T>
static void	mergeInsert( T& main, T& pend, size_t elementSize ) {
	size_t	jPrevious = 1, jCurrent = 3, jN = 3, treeSize;
	size_t	i = jCurrent - jPrevious - 1;
	size_t	iMax = pend.size() / elementSize - 1;

	if (i > iMax)
		i = iMax;
	treeSize = fetchTreeSize(jN, jCurrent,
						  jPrevious, pend.size(), elementSize);
	while (!pend.empty()) {
		resolveInsertion(main, pend, i, treeSize, elementSize);
		if (i > 0)
			--i;
		else {
			nextJacobsthal(jPrevious, jCurrent, jN);
			i = jCurrent - jPrevious - 1;
			iMax = pend.size() / elementSize - 1;
			if (i > iMax)
				i = iMax;
			treeSize = fetchTreeSize(jN, jCurrent,
							jPrevious, pend.size(), elementSize);
		}
	}
};

static size_t	maxElementSize( size_t dataSize ) {
	size_t	thirdSize = dataSize / 3;
	size_t	max = 2;
	while (max <= thirdSize)
		max *= 2;
	return max / 2;
}

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
	if (main.size() < 3 || isSort(main))
		return main;
	T	pend;
	size_t	elementSize = maxElementSize(main.size());
	while (elementSize > 0) {
		buildChains(main, pend, elementSize);
		mergeInsert(main, pend, elementSize);
		if (isSort(main))
			return main;
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
