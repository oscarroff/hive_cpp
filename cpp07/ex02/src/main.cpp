/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 09:55:38 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/19 09:56:30 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"
#include <iostream>

int	main( void ) {
	std::cout << "=== Construction & size() ===\n";
	Array<int>	array1;
	std::cout << "array1 size: " << array1.size() << "\n";
	std::cout << "\n";

	std::cout << "=== Initial Length Construction & Subscript [] Operator ===\n";
	Array<float>	array2(3);
	array2[1] = 4.2f;
	std::cout << "array2 size: " << array2.size() << "\n"
		<< "array2[0]: " << array2[0] << "\n"
		<< "array2[1]: " << array2[1] << "\n"
		<< "array2[2]: " << array2[2] << "\n";
	std::cout << "\n";

	std::cout << "=== Copy Construction & Deep Copy ===\n";
	Array<float>	array3(array2);
	array3[2] = 0.0042f;
	std::cout << "array3 size: " << array3.size() << "\n"
		<< "array3[0]: " << array3[0] << "\n"
		<< "array3[1]: " << array3[1] << "\n"
		<< "array3[2]: " << array3[2] << "\n";
	std::cout << "\n";
	std::cout << "array2[0] address: " << &array2[0] << "\n";
	std::cout << "array3[0] address: " << &array2[0] << "\n";
	std::cout << "\n";

	std::cout << "=== Assignment Operator ===\n";
	Array<int>	array4(2);
	array4[0] = 420000;
	array4[1] = 420;
	std::cout << "array4 size: " << array4.size() << "\n"
		<< "array4[0]: " << array4[0] << "\n"
		<< "array4[1]: " << array4[1] << "\n";
	std::cout << "\n";
	std::cout << "array1 pre copy assignment\n";
	std::cout << "array1 size: " << array1.size() << "\n";
	std::cout << "\n";
	array1 = array4;
	std::cout << "array1 post copy assignment\n";
	std::cout << "array1 size: " << array1.size() << "\n"
		<< "array1[0]: " << array1[0] << "\n"
		<< "array1[1]: " << array1[1] << "\n";
	std::cout << "\n";

	std::cout << "=== std::exception ===\n";
	try {
		std::cout << "array4[100]: " << array4[100] << "\n";
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}
	return 0;
};
