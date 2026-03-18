/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 13:42:48 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/18 15:22:43 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Awesome.hpp"

// Constructor to initialize member data
PhoneBook::PhoneBook() : _i(0), _size(0) {};
PhoneBook::~PhoneBook() {};

// Getters
int		PhoneBook::getSize() {
	return _size ;
}

// Setters
void	PhoneBook::add(Contact contact) {
	_contacts[_i] = contact;
	_contacts[_i].setIndex(_i + 1);
	_i++;
	_size++;
	if (_i >= 8)
		_i = 0;
	if (_size > 8)
		_size = 8;
}

// Display
void	PhoneBook::display() {
	for (int i = 0; i < _size; i++) {
		std::cout << std::setw(10) << "index" << "|" << std::setw(10) << "first"
			<< "|" << std::setw(10) << "last" << "|" << std::setw(10)
			<< "nickname" << std::endl;
		std::cout << std::string(43, '-') << std::endl;
		std::cout << std::right << std::setw(10) << _contacts[i].getIndex() << "|";
		std::cout << std::right << std::setw(10)
				<< truncate(_contacts[i].getFirst()) << "|";
		std::cout << std::right << std::setw(10)
				<< truncate(_contacts[i].getLast()) << "|";
		std::cout << std::right << std::setw(10)
				<< truncate(_contacts[i].getNickname()) << std::endl;
	}
}
int	PhoneBook::getContact(int index) {
	if (index < 1 || index > _size) {
		std::cout << "index is invalid, please try again...\n";
		return (FAIL);
	}
	clearConsole();
	index--;
	std::cout << "O _ R O F F  FoneBuk\n";
	std::cout << "DISPLAY contact card\n";
	std::cout << "index:\t\t" << _contacts[index].getIndex() << std::endl;
	std::cout << std::string(17, '-') << std::endl;
	std::cout << "first:\t\t" << _contacts[index].getFirst() << std::endl;
	std::cout << "last:\t\t" << _contacts[index].getLast() << std::endl;
	std::cout << "nickname:\t" << _contacts[index].getNickname() << std::endl;
	std::cout << "number:\t\t" << _contacts[index].getNumber() << std::endl;
	std::cout << "darkest secret:\t" << _contacts[index].getSecret() << "\n\n";
	return (SUCCESS);
}
