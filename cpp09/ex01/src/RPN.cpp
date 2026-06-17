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
#include <cstring>   // for std::strchr
#include <limits.h>  // for INT_MAX and INT_MIN
#include <stdexcept> // for std::runtime_error
#include <stack> // for std::stack

// Forward declarations
static void	parseOperator( std::stack<int>& stack, char operation );
static void	parseArgument( std::stack<int>& stack, char argument );

int	RPN::calculate( const char *expression ) {
	std::stack<int>	stack;
	bool	spaceToggle = false;

	while (*expression == ' ')
		++expression;
	if (*expression == '\0')
		throw std::runtime_error("not enough instructions");
	while (*expression) {
		if (std::strchr(numChars, *expression)) {
			if (spaceToggle == true)
				throw std::runtime_error("invalid syntax, single characters only");
			parseArgument(stack, *expression);
			++expression;
		}
		else if (*expression == ' ')
			while (*expression == ' ')
				++expression;
		else
			throw std::runtime_error("invalid character");
		spaceToggle = !spaceToggle;
	}
	if (stack.size() > 1)
		throw std::runtime_error("invalid syntax, not enough operators");
	return stack.top();
};

static void	parseArgument( std::stack<int>& stack, char argument ) {
	if (std::strchr(RPN::digitChars, argument))
		stack.push(argument - RPN::atoiASCII);
	else if (stack.size() < 2)
		throw std::runtime_error("invalid syntax, too many operators");
	else
		parseOperator(stack, argument);
};

static void	parseOperator( std::stack<int>& stack, char operation ) {
	int		right = stack.top();
	stack.pop();
	long	left = static_cast<long>(stack.top());
	stack.pop();
	switch (operation) {
		case '+': {
			left += right;
			break ;
		}
		case '-': {
			left -= right;
			break ;
		}
		case '*': {
			left *= right;
			break ;
		}
		case '/': {
			if (right == 0)
				throw std::runtime_error("division by zero");
			left /= right;
		}
	}
	if (left > INT_MAX)
		throw std::runtime_error("integer too big");
	if (left < INT_MIN)
		throw std::runtime_error("integer too small");
	stack.push(static_cast<int>(left));
}
