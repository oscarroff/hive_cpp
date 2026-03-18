/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Awesome.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 13:50:42 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/18 16:47:33 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AWESOME_H
# define AWESOME_H

# include <iostream>
# include <iomanip>
# include <stdexcept>
# include <string>
# include <cstring>
# include <limits>
# include <cmath>
# include <algorithm>

# include "Contact.hpp"
# include "PhoneBook.hpp"

# define FAIL 1
# define SUCCESS 0

void		ignoreLine();
bool		isNumber(const std::string &s);
std::string	truncate(std::string str);
void		clearConsole(void);

#endif
