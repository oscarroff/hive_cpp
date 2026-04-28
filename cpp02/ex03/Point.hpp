/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:53:53 by thblack-          #+#    #+#             */
/*   Updated: 2026/04/28 17:03:09 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Fixed.hpp"

class	Point {
private:
	Fixed const	_x;
	Fixed const _y;
public:
	Point();
	Point( const Point& other );
	Point&	operator=( const Point& other );
	~Point();
	Point( const float x, const float y );
};
