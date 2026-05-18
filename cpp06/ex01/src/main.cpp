/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:24:25 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/17 18:55:34 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <cstdint>
#include <iostream>

int	main( void ) {
	Data	a = {1729, "Hardy-Ramanujan"};
	Data	*ptr1 = &a;
	uintptr_t	raw = Serializer::serialize(ptr1);
	Data	*ptr2 = Serializer::deserialize(raw);
	std::cout << "ptr1: " << ptr1 << "\n";
	std::cout << "raw: " << raw << "\n";
	std::cout << "ptr2: " << ptr2 << "\n";
	if (ptr1 == ptr2)
		std::cout << "They are the same!\n";
	std::cout << "ptr1: " << ptr1->_name
		<< " likes the number " << ptr1->_x << "\n";
	std::cout << "ptr2: " << ptr2->_name
		<< " likes the number " << ptr2->_x << "\n";
	return 0;
};
