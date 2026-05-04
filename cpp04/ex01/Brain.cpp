/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:07:59 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/04 17:02:21 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

// Constructors
Brain::Brain() : _lastThought(0) {
	std::cout << "Default Brain constructor called\n";
};
Brain::Brain( const Brain& other ) : _lastThought(other._lastThought) {
	std::copy(other._ideas, other._ideas + 100, this->_ideas);
	std::cout << "Brain copy constructor called\n";
};
Brain& Brain::operator=( const Brain& other ) {
	if (this != &other) {
		std::copy(other._ideas, other._ideas + 100, this->_ideas);
		this->_lastThought = other._lastThought;
	}
	std::cout << "Brain copy assignment constructor called\n";
	return *this;
};
Brain::~Brain() {
	std::cout << "Brain destructor called\n";
};
void	Brain::eureka( const std::string& idea ) {
	if (this->_lastThought == 100)
		this->_lastThought = 0;
	this->_ideas[_lastThought++] = idea;
};
const std::string	Brain::mindPalace( const unsigned int& memoryBank ) {
	if (memoryBank >= 100)
		return "We do not have that many brainz\n";
	if (this->_ideas[memoryBank].empty())
		return "Empty brainz\n";
	return this->_ideas[memoryBank];
};
