/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:24:25 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/18 11:50:29 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream> // for std::cout/cerr
#include <random> // for mt19937 randomness

// Forward declarations
Base*	generate( void );
void	identify( Base* p );
void	identify( Base& p );

// Enum for clearly showing which type is created in generate()
enum	ABC {
	ATYPE,
	BTYPE,
	CTYPE,
};

int	main( void ) {
	Base*	test = generate();
	identify(test);
	identify(*test);
	delete test;
	return 0;
};

Base*	generate( void ) {
	static std::mt19937 eng{std::random_device{}()};
	static std::uniform_int_distribution<int> dist(0, 2);
	ABC	abc = static_cast<ABC>(dist(eng));
	Base*	base;
	switch (abc) {
		case ATYPE: base = new A; break;
		case BTYPE: base = new B; break;
		case CTYPE: base = new C; break;
	};
	return base;
};

void	identify( Base* p ) {
	A*	testA = dynamic_cast<A*>(p);
	if (testA != nullptr) {
		std::cout << "pointer object is type A\n";
		return ;
	}
	B*	testB = dynamic_cast<B*>(p);
	if (testB != nullptr) {
		std::cout << "pointer object is type B\n";
		return ;
	}
	C*	testC = dynamic_cast<C*>(p);
	if (testC != nullptr) {
		std::cout << "pointer object is type C\n";
		return ;
	}
	std::cout << "pointer object is an unknown type\n";
};

void	identify( Base& p ) {
	try {
		A&	testA = dynamic_cast<A&>(p);
		std::cout << "reference object is type A\n";
		(void)testA;
		return ;
	}
	catch (std::exception& e) {}
	try {
		B&	testB = dynamic_cast<B&>(p);
		std::cout << "reference object is type B\n";
		(void)testB;
		return ;
	}
	catch (std::exception& e) {}
	try {
		C&	testC = dynamic_cast<C&>(p);
		std::cout << "reference object is type C\n";
		(void)testC;
		return ;
	}
	catch (std::exception& e) {}
	std::cout << "reference object is an unknown type\n";
};
