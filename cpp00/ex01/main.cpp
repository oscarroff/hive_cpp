/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 11:40:14 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/15 16:02:49 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <limits>
#include <cmath>

class	Contact {
private:
	int			index;
	std::string	first;
	std::string	last;
	std::string	nickname;
	int			number;
	std::string	secret;
public:
	// Constructor to initialize member data
	Contact() : index(0), first(""), last(""), nickname(""), number(0),
				secret("") {}
	// Getters
	int			getIndex() { return index; }
	std::string	getFirst() { return first; }
	std::string	getLast() { return last; }
	std::string	getNickname() { return nickname; }
	int			getNumber() { return number; }
	std::string	getSecret() { return secret; }
	// Setters
	void		setIndex(size_t index) { this->index = index; }
	// void		setFirst(std::string first) { this->first = first; }
	// void		setLast(std::string last) { this->last = last; }
	// void		setNickname(std::string nickname) { this->nickname = nickname; }
	// void		setNumber(int number) { this->number = number; }
	// void		setSecret(std::string secret) { this->secret = secret; }
	void		setContact(std::string first, std::string last,
		std::string nickname, int number, std::string secret) {
		// FIXME: Not allowed in header
		this->first = first, this->last = last, this->nickname = nickname,
		this->number = number, this->secret = secret;
	}
	// Display contact member data
	void		display() {
		std::cout << index << first << last << nickname << std::endl;
	}
};

class	PhoneBook {
private:
	Contact contacts[8];
	int		i;
	int		size;
public:
	PhoneBook() : i(0), size(0) {};
	// FIXME: Not allowed in header, everything from ':'
	void	add(Contact contact) {
		contacts[i] = contact;
		contacts[i].setIndex(i + 1);
		i++;
		size++;
		if (i >= 8)
			i = 0;
		if (size > 8)
			size = 8;
	}
	void	display() {
		for (int i = 0; i < size; i++) {
		std::cout << std::right << std::setw(10) << contacts[i].getIndex() << "|";
		std::cout << std::right << std::setw(10) << contacts[i].getFirst() << "|";
		std::cout << std::right << std::setw(10) << contacts[i].getLast() << "|";
		std::cout << std::right << std::setw(10) << contacts[i].getNickname() << std::endl;
		}
	}
	void	getContact(int index) {
		if (index < 1 || index > size) {
			std::cout << "index is invalid, please try again...\n";
			return ;
		}
		index--;
		std::cout << "index:\t\t" << contacts[index].getIndex() << std::endl;
		std::cout << "first:\t\t" << contacts[index].getFirst() << std::endl;
		std::cout << "last:\t\t" << contacts[index].getLast() << std::endl;
		std::cout << "nickname:\t" << contacts[index].getNickname() << std::endl;
		std::cout << "number:\t\t" << contacts[index].getNumber() << std::endl;
		std::cout << "darkest secret:\t" << contacts[index].getSecret() << std::endl;
	}
};

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool is_number(const std::string &s)
{
	std::string::const_iterator i = s.begin();
	while (i != s.end() && std::isdigit(*i))
		++i;
	return !s.empty() && i == s.end();
}

void	contact_add(PhoneBook &book)
{
	std::string	first, last, nickname, number_string, secret;
	int			number;
	Contact		contact;

	ignoreLine();
	std::cout << "first name:\n";
	std::cin >> first;
	ignoreLine();
	std::cout << "last name:\n";
	std::cin >> last;
	ignoreLine();
	std::cout << "nickname:\n";
	std::cin >> nickname;
	ignoreLine();
	while (true)
	{
		std::cout << "number:\n";
		std::cin >> number_string;
		if (is_number(number_string))
			break ;
		std::cout << "error: input expects a valid numerical value\n";
	}
	ignoreLine();
	std::cout << "darkest secret:\n";
	std::cin >> secret;
	ignoreLine();
	number = std::stoi(number_string);
	contact.setContact(first, last, nickname, number, secret);
	book.add(contact);
	return ;
}

void	contact_search(PhoneBook &book)
{
	std::string	index_string;

	book.display();
	ignoreLine();
	while (true)
	{
		std::cout << "number:\n";
		std::cin >> index_string;
		if (is_number(index_string))
			break ;
		std::cout << "error: input expects a valid numerical value\n";
	}
	int	index = std::stoi(index_string);
	book.getContact(index);
	return ;
}

int	main(void)
{
	std::string	input;
	PhoneBook	book;

	std::cout << "O _ R O F F  FoneBuk\n";
	while (true)
	{
		std::cout << "Input 'ADD', 'SEARCH' or 'EXIT'\n";
		std::cin >> input;
		if (input.compare("ADD") == 0)
			contact_add(book);
		else if (input.compare("SEARCH") == 0)
			contact_search(book);
		else if (input.compare("EXIT") == 0)
			return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
