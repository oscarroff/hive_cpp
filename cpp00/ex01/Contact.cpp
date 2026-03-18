/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:42:24 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/18 14:15:01 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Awesome.hpp"

// Constructor to initialize member data
Contact::Contact() : _index(0), _first(""), _last(""), _nickname(""),
			_number(""), _secret("") {}
Contact::~Contact() {}

// Getters
int	Contact::getIndex()
{
	return _index;
}
std::string	Contact::getFirst()
{
	return _first;
}
std::string	Contact::getLast()
{
	return _last;
}
std::string	Contact::getNickname()
{
	return _nickname;
}
std::string	Contact::getNumber()
{
	return _number;
}
std::string	Contact::getSecret()
{
	return _secret;
}

// Setters
void	Contact::setIndex(size_t index)
{
	this->_index = index;
}
void	Contact::setContact(std::string first, std::string last,
	std::string nickname, std::string number, std::string secret)
{
	this->_first = first, this->_last = last, this->_nickname = nickname,
	this->_number = number, this->_secret = secret;
}

// Display contact member data
void	Contact::display()
{
	std::cout << _index << _first << _last << _nickname << std::endl;
}
