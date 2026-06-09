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

template <typename T>
static void	sortPairRange( T& in, size_t position, size_t pairSize ) {
	auto	first1 = std::next(in.begin(), position);
	auto	last1 = std::next(in.begin(), position + pairSize - 1);
	auto	first2 = std::next(in.begin(), position + pairSize);
	std::swap_ranges(first1, last1, first2); 
};

template <typename T>
T	PmergeMe<T>::mergeInsertSort( const T& in ) {
	T		res(in);
	size_t	pairSize = 2;
	while (res.size() / pairSize > 0) {
		for (size_t i = 0; res.size() - i >= pairSize; i += pairSize) 
			sortPairRange(res, i, pairSize);
		pairSize *= 2;
	}
	return res;
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
