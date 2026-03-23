/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 11:40:14 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/18 16:49:21 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Awesome.hpp"

void	contactAdd(PhoneBook &book);
void	contactSearch(PhoneBook &book);

int	main(void)
{
	std::string	input;
	PhoneBook	book;

	clearConsole();
	while (true)
	{
		std::cout << "O _ R O F F  FoneBuk\n";
		std::cout << "Input 'ADD', 'SEARCH' or 'EXIT'\n";
		if (!std::getline(std::cin, input)) {
			if (streamError())
				break ;
			else
				continue ;
		}
		std::transform(input.begin(), input.end(), input.begin(), ::toupper);
		clearConsole();
		if (input.compare("ADD") == 0)
			contactAdd(book);
		else if (input.compare("SEARCH") == 0)
			contactSearch(book);
		else if (input.compare("EXIT") == 0)
		{
			std::cout << "O _ R O F F  FoneBuk\n";
			std::cout << "EXIT Goodbye! :)\n";
			return (EXIT_SUCCESS);
		}
		clearConsole();
	}
	return (EXIT_SUCCESS);
}

void	contactAdd(PhoneBook &book)
{
	std::string	first, last, nickname, number, secret;
	Contact		contact;

	ignoreLine();
	std::cout << "O _ R O F F  FoneBuk\n";
	std::cout << "ADD new contact\n";
	std::cout << "first name: ";
	std::cin >> first;
	ignoreLine();
	std::cout << "last name: ";
	std::cin >> last;
	ignoreLine();
	std::cout << "nickname: ";
	std::cin >> nickname;
	ignoreLine();
	std::cout << "number: ";
	std::cin >> number;
	ignoreLine();
	std::cout << "darkest secret: ";
	std::cin >> secret;
	ignoreLine();
	contact.setContact(first, last, nickname, number, secret);
	book.add(contact);
	return ;
}

void	contactSearch(PhoneBook &book)
{
	std::string	index_string;

	if (book.getSize() == 0)
	{
		std::cout << "O _ R O F F  FoneBuk\n";
		std::cout << "contact list is empty, ADD before your SEARCH\n";
		ignoreLine();
		std::cout << "hit enter to return to main menu... ";
		std::cin.get();
		return ;
	}
	std::cout << "O _ R O F F  FoneBuk\n";
	std::cout << "SEARCH existing contact\n";
	book.display();
	ignoreLine();
	while (true)
	{
		std::cout << "show contact card for index: ";
		std::cin >> index_string;
		if (!isNumber(index_string))
		{
			std::cout << "index must be a number, please try again...\n";
			continue ;
		}
		int	index = std::stoi(index_string);
		if (book.getContact(index) == SUCCESS)
			break ;
	}
	ignoreLine();
	std::cout << "hit enter to return to main menu... ";
	std::cin.get();
	return ;
}
