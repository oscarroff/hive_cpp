/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 13:52:29 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/18 14:50:52 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Awesome.hpp"

void	ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool isNumber(const std::string &s)
{
	std::string::const_iterator i = s.begin();
	while (i != s.end() && std::isdigit(*i))
		++i;
	return !s.empty() && i == s.end();
}

std::string	truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	clearConsole(void)
{
	try {
		std::cout << "\033[2J\033[H";
		std::cout.flush();
	} catch (...) {
		std::system("clear");
	}
}

bool	streamError(void)
{
	if (std::cin.eof()) {
		std::cin.clear();
		ignoreLine();
		return false;
	}
	return true;
}
