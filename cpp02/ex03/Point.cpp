/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:03:37 by thblack-          #+#    #+#             */
/*   Updated: 2026/04/28 17:11:52 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
	std::cout << "Default constructor called\n";
};
Point::Point( const Point& other ) : _x(other._x), _y(other._y) {
	std::cout << "Copy constructor called\n";
};
Point&	Point::operator=( const Point& other ) {
	std::cout << "Copy assignment constructor called\n";
	if (this != &other)
	{
		this->_x = other._x;
		this->_y = other._y;
	}
};
Point::~Point() {
	std::cout << "Destructor called\n";
};
Point::Point( const float x, const float y ) : _x(x), _y(y) {
	std::cout << "XY float constructor called\n";
};
