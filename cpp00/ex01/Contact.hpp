/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:34:21 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/18 16:35:06 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

class	Contact {
private:
	int			_index;
	std::string	_first;
	std::string	_last;
	std::string	_nickname;
	std::string	_number;
	std::string	_secret;
public:
	// Constructor to initialize member data
	Contact();
	~Contact();
	// Getters
	int			getIndex();
	std::string	getFirst();
	std::string	getLast();
	std::string	getNickname();
	std::string	getNumber();
	std::string	getSecret();
	// Setters
	void	setIndex(size_t index);
	void	setContact(std::string first, std::string last,
		std::string nickname, std::string number, std::string secret);
	void	display();
};

#endif
