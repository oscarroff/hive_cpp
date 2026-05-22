/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:24:25 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/19 14:35:14 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <algorithm>

template <typename T>
typename T::iterator	easyfind( T& haystack, int needle ) {
	return std::find(haystack.begin(), haystack.end(), needle);
};

template <typename T>
typename T::const_iterator	easyfind( const T& haystack, const int needle ) {
	return std::find(haystack.begin(), haystack.end(), needle);
};
