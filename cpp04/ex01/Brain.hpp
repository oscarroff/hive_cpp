/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:14:16 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/04 16:49:33 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	Brain {
private:
	std::string	_ideas[100];
	unsigned int	_lastThought;
public:
	Brain();
	Brain( const Brain& other );
	Brain& operator=( const Brain& other );
	~Brain();
	void	eureka( const std::string& idea );
	const std::string	mindPalace( const unsigned int& memoryBank );
};
