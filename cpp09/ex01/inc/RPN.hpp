/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:48:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/06/08 11:27:35 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>

class RPN {
public:
	// Constructors & destructors
	RPN() = delete;
	RPN(const RPN &other) = delete;
	RPN &operator=(const RPN &other) = delete;
	~RPN() = delete;

	static std::deque<int>	parseInput( const char* in );
	static int	calculate( std::deque<int>& equation );

	static constexpr const char*	digitChars = "0123456789";
	static constexpr const char*	opChars = "+-/*";
	static constexpr const char*	numChars = "0123456789+-*/ ";
	static constexpr int			atoiASCII = 48;
};
