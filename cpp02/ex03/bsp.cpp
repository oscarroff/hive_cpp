/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:21:34 by thblack-          #+#    #+#             */
/*   Updated: 2026/04/28 18:11:43 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// BSP (Binary Space Partitioning) function that checks if point is inside the
// triangle described by the three verticies abc. Returns true if point inside
// the triangle, false otherwise. If the point IS a vertice or on an edge it
// will return false also.
bool	bsp( Point const a, Point const b, Point const c, Point const point) {
	// Calculate cross products (difference in angle) between each side of
	// the triangle as vectors and the point.
	Fixed	crossAB = (b.getX() - a.getX()) * (point.getY() - a.getY())
		- (b.getY() - a.getY()) * (point.getX() - a.getX());
	Fixed	crossBC = (c.getX() - b.getX()) * (point.getY() - b.getY())
		- (c.getY() - b.getY()) * (point.getX() - b.getX());
	Fixed	crossCA = (a.getX() - c.getX()) * (point.getY() - c.getY())
		- (a.getY() - c.getY()) * (point.getX() - c.getX());
	// Logic:
	// - if all cross products have the same sign then the point is inside
	// - if a cross product is zero then the point is on the line
	// - if signs of cross products differ then the point is outside
	bool	has_neg = (crossAB < 0) || (crossBC < 0) || (crossCA < 0);
	bool	has_pos = (crossAB > 0) || (crossBC > 0) || (crossCA > 0);
	bool	has_zero = (crossAB == 0) || (crossBC == 0) || (crossCA == 0);
	if (has_zero || (has_neg && has_pos))
		return false;
	return true;
};
