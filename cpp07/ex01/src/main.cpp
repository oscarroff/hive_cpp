/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:36:46 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/18 17:37:49 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int	main(void)
{
	int			array1[5] = {6, 42, 9, 20, -123};
	float		array2[3] = {4.2f, 3.4e5f, 9.7e-10f};
	std::string	array3[2] = {"I like... birds", "Don't care about the rocket launch"};
	const int	array4[5] = {6, 42, 9, 20, -123};

	std::cout << "Printing\n";
	std::cout << "array1:\n";
	iter(array1, 5, printArray<int>);
	std::cout << "\n";
	std::cout << "array2:\n";
	iter(array2, 3, printArray<float>);
	std::cout << "\n";
	std::cout << "array3:\n";
	iter(array3, 2, printArray<std::string>);

	std::cout << "\n";
	std::cout << "\n";
	std::cout << "Increment & Decrement\n";
	std::cout << "array1:\n";
	iter(array1, 5, increment<int>);
	iter(array1, 5, printArray<int>);
	std::cout << "\n";
	std::cout << "array2:\n";
	iter(array2, 3, decrement<float>);
	iter(array2, 3, printArray<float>);

	std::cout << "\n";
	std::cout << "\n";
	std::cout << "Const Array\n";
	iter(array4, 5, printArray<const int>);
	return (0);
}
