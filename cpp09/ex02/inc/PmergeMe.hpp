/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:48:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/06/08 13:19:31 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <list>

using vector = std::vector<unsigned int>;
using list = std::list<unsigned int>;
template <typename T>
using chain = std::vector<typename T::iterator>;

template <typename T>
class PmergeMe {
public:
	// Constructors & destructors
	PmergeMe() = delete;
	PmergeMe(const PmergeMe &other) = delete;
	PmergeMe &operator=(const PmergeMe &other) = delete;
	~PmergeMe() = delete;

	static T	loadData( char** args );
	static bool	isSort( T& data );
	static T	fordJohnsonAlgo( const T& in );
};
