/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:48:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/15 11:55:35 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Intern {
private:
public:
    // Constructors & Destructors
    Intern() = default;
    Intern( const Intern& other ) = default;
    Intern &operator=( const Intern &other ) = default;
    ~Intern() = default;

	// Member Functions
	AForm*	makeForm( const std::string& name, const std::string& target ) const;
};
