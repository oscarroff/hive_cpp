/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 12:43:12 by thblack-          #+#    #+#             */
/*   Updated: 2026/04/28 17:51:55 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool	bsp( Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point	cornerA(0, 0);
	Point	cornerB(5, 0);
	Point	concerC(0, 5);
	Point	point1(1, 1);
	Point	point2(5, 5);
	Point	point3(2.5, 2.5);
	if (bsp(cornerA, cornerB, concerC, point1))
		std::cout << "Point 1 is inside the triangle\n";
	else
		std::cout << "Point 1 is outside the triangle\n";
	if (bsp(cornerA, cornerB, concerC, point2))
		std::cout << "Point 2 is inside the triangle\n";
	else
		std::cout << "Point 2 is outside the triangle\n";
	if (bsp(cornerA, cornerB, concerC, point3))
		std::cout << "Point 3 is inside the triangle\n";
	else
		std::cout << "Point 3 is outside the triangle\n";
	return (0);
}
