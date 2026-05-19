/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:27:22 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/19 14:24:13 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*
 * EasyFind
 * Find the 1st occurence of the 2nd parameter in the 1st parameter
 * We handle only sequential containers as the 1st parameter
 * E.g. arrays and vectors, not linked lists
*/

template <typename T>
typename T::iterator	easyfind( T& t, const int );

template <typename T>
typename T::const_iterator	easyfind( const T& t, int );
