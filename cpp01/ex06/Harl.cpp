/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:48:03 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/25 17:09:37 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl () {};
Harl::~Harl () {};

void	Harl::complain( std::string level )
{
	std::string	levels[4] = {
		"DEBUG", "INFO", "WARNING", "ERROR"
	};
	void (Harl::*functions[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*functions[i])();
			return ;
		}
	}
	std::cout << "Harl 2.0: invalid level\n";
}

void	Harl::debug()
{
	std::cout << "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-special ketchup burger. I really do!\n";
}
void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. \
You didn’t put enough bacon in my burger! If you did, I wouldn’t be \
asking for more!\n";
}
void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve \
been coming for years, whereas you started working here just last month.\n";
}
void	Harl::error()
{
	std::cerr << "This is unacceptable! I want to speak to the manager now.\n";
}

int	hashString( std::string& str ) {
	if (str == "DEBUG") return 0;
	if (str == "INFO") return 1;
	if (str == "WARNING") return 2;
	if (str == "ERROR") return 3;
	return -1;
}

std::string	unhashString( int index ) {
	if (index == 0)	return "DEBUG";
	if (index == 1)	return "INFO";
	if (index == 2)	return "WARNING";
	if (index == 3)	return "ERROR";
	return "";
}

void	Harl::message( int index )
{
	std::string	level = unhashString(index);
	void (Harl::*functions[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};
	std::cout << "[ "  << level << " ]\n";
	(this->*functions[index])();
	std::cout << "\n";
}

void	Harl::filter( std::string level )
{
	int	index = hashString(level);
	if (index < 0) {
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		return ;
	}
	switch (index) {
		case 0:
			message(0);
			message(1);
			message(2);
			message(3);
			break ;
		case 1:
			message(1);
			message(2);
			message(3);
			break ;
		case 2:
			message(2);
			message(3);
			break ;
		case 3:
			message(3);
			break ;
	}
}
