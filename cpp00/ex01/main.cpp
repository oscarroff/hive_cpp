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
#include <cstdlib>

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
			clearConsole();
			std::cout << "O _ R O F F  FoneBuk\n";
			std::cout << "CTRL-D detected\n";
			std::cout << "EXIT Goodbye! :)\n";
			return (EXIT_SUCCESS);
		}
		if (input.empty()) {
			clearConsole();
			continue ;
		}
		std::transform(input.begin(), input.end(), input.begin(), ::toupper);
		clearConsole();
		if (input.compare("ADD") == 0)
			contactAdd(book);
		else if (input.compare("SEARCH") == 0)
			contactSearch(book);
		else if (input.compare("EXIT") == 0) {
			std::cout << "O _ R O F F  FoneBuk\n";
			std::cout << "EXIT Goodbye! :)\n";
			return (EXIT_SUCCESS);
		}
		clearConsole();
	}
}

void	inputDetails(std::string *field, std::string prompt)
{
	while (true) {
		std::cout << prompt << ": ";
		std::getline(std::cin, *field);
		if (field->empty()) {
			continue ;
		}
		return ;
	}
}

void	contactAdd(PhoneBook &book)
{
	std::string	first, last, nickname, number, secret;
	Contact		contact;

	std::cout << "O _ R O F F  FoneBuk\n";
	std::cout << "ADD new contact\n";
	inputDetails(&first, "first name");
	inputDetails(&last, "last name");
	inputDetails(&nickname, "nickname");
	inputDetails(&number, "number");
	inputDetails(&secret, "darkest secret");
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
		std::cout << "hit enter to return to main menu... ";
		std::cin.get();
		return ;
	}
	std::cout << "O _ R O F F  FoneBuk\n";
	std::cout << "SEARCH existing contact\n";
	book.display();
	while (true)
	{
		std::cout << "\nshow contact card for index: ";
		if (!std::getline(std::cin, index_string))
			break ;
		if (!isNumber(index_string))
		{
			std::cout << "index must be a number, please try again...\n";
			continue ;
		}
		int	index = std::stoi(index_string);
		if (book.getContact(index) == SUCCESS)
			break ;
	}
	std::cout << "hit enter to return to main menu... ";
	std::cin.get();
	return ;
}
