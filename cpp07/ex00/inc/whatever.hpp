/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:27:22 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/18 17:41:29 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T> void	swap( T& a, T& b ) {
	T	temp = a;
	a = b;
	b = temp;
};

template <typename T> T&	min( T& a, T& b ) {
	return b <= a ? b : a;
};

template <typename T> T&	max( T& a, T& b ) {
	return b >= a ? b : a;
};
