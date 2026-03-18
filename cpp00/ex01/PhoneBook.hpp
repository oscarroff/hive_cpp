/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 13:42:51 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/18 16:36:27 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class	PhoneBook {
private:
	Contact _contacts[8];
	int		_i;
	int		_size;
public:
	PhoneBook();
	~PhoneBook();
	int		getSize();
	void	add(Contact contact);
	void	display();
	int		getContact(int index);
};

#endif
