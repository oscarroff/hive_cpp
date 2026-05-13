/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:48:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/13 12:52:44 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	std::string	_target;
public:
	// Constructors & Destructors
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other) = delete;
	~ShrubberyCreationForm();

	const std::string&	getTarget() const;
	void				doThings() const override;
};

#define SHRUBS "\
  .^^.        .^^^^.        .^^^.        .^^^^.        .^^^. \n\
^/||||\\^.  .^/||||||\\^.  .^/|||||\\^.  .^/||||||\\^.  .^/|||||\\^.\n\
   ||           ||           |||           ||           |||    \n\
   ||           ||           |||    NI!    ||     | |   |||    \n\
   O|   O       ||   .-~~~~~~~~~-.         || O    O	|||    \n\
  /|\\  /|\\      ||  .'  *  .  *   '.       ||/|\\  /|\\	|||    \n\
  / \\  / \\         /  .  *   .  *   \\        / \\  / \\	|||    \n\
###################|   *  .  *  .   |##########################\n\
---------------------------------------------------------------\n"
