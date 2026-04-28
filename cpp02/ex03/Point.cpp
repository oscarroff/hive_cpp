/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:03:37 by thblack-          #+#    #+#             */
/*   Updated: 2026/04/28 17:53:10 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) { };
Point::Point( const Point& other ) : _x(other._x), _y(other._y) {};
Point::~Point() {};
Point::Point( const float x, const float y ) : _x(x), _y(y) {};
Fixed	Point::getX( void ) const {
	return this->_x;
};
Fixed	Point::getY( void ) const {
	return this->_x;
};
