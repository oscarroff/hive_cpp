/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:48:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/06/08 11:56:13 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstring> // for std::strchr
#include <stdexcept> // for std::runtime_error
#include <limits.h> // for INT_MAX and INT_MIN

std::deque<int>	RPN::parseInput( const char *in ) {
	std::string	str(in);
	// Early throws
	if (str.length() == 0)
		throw std::runtime_error("no input");
	if (str.find_first_not_of(numChars) != std::string::npos)
		throw std::runtime_error("invalid char");
	if (!std::strchr(digitChars, str[str.find_first_not_of(' ')]))
		throw std::runtime_error("invalid order");

	// Fill stack
	std::deque<int>	result;
	bool	numToggle = true;
	bool	spaceToggle = true;
	auto it = str.begin();
	while (*it == ' ')
		++it;
	result.push_back(*it++);
	while (it != str.end()) {
		if (*it == ' ') {
			spaceToggle = false;
			++it;
			continue;
		}
		// Throw invalid order
		if (spaceToggle == true && (std::strchr(digitChars, *it) || std::strchr(opChars, *it)))
			throw std::runtime_error("unexpected instruction, only single-char instructions allowed");
		if (numToggle == true && !std::strchr(digitChars, *it))
			throw std::runtime_error("unexpected operator");
		else if (numToggle == false && !std::strchr(opChars, *it))
			throw std::runtime_error("unexpected digit");
		result.push_back(*it);
		numToggle = !numToggle;
		spaceToggle = true;
		++it;
	}
	if (result.size() < 3)
		throw std::runtime_error("not enough instructions to calculate");
	if (result.size() % 2 != 1)
		throw std::runtime_error("invalid syntax");
	return result;
};

int	RPN::calculate( std::deque<int>& equation ) {
	long	left;
	int		right;
	char	operation;
	left = equation.front() - atoiASCII;
	equation.pop_front();
	while (equation.size() > 1) {
		right = equation.front() - atoiASCII;
		equation.pop_front();
		operation = equation.front();
		equation.pop_front();
		if (operation == '+')
			left += right;
		else if (operation == '-')
			left -= right;
		else if (operation == '*')
			left *= right;
		else if (operation == '/')
			left /= right;
		if (left > INT_MAX)
			throw std::runtime_error("integer too big");
		if (left < INT_MIN)
			throw std::runtime_error("integer too small");
	}
	if (equation.size() > 0)
		throw std::runtime_error("invalid syntax at calculation stage");
	return static_cast<int>(left);
};
