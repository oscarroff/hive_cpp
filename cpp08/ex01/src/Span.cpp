/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:48:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/20 09:11:13 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits> // for INT_MAX, UINT_MAX etc.
#include <cmath> // for labs()
#include <iostream> // for std::cout
#include <vector> // for std::vector
#include <algorithm> // for sort()

// Default constructor
Span::Span() : _size(0), _capacity(0) {
	this->_array = new int[0];
};

// Size constructor
Span::Span( const unsigned int N ) : _size(0), _capacity(N) {
	this->_array = new int[N];
};

// Copy constructor
Span::Span( const Span& other ) : _size(other._size), _capacity(other._capacity) {
	this->_array = new int[this->_capacity];
	for (size_t i = 0; i < this->_size; i++) {
		this->_array[i] = other._array[i];
	}
};

// Copy assignment operator
Span& Span::operator=( const Span& other ) {
	if (this != &other) {
		delete[] this->_array;
		this->_size = other._size;
		this->_capacity = other._capacity;
		this->_array = new int[this->_capacity];
		for (size_t i = 0; i < this->_size; i++) {
			this->_array[i] = other._array[i];
		}
	}
    return *this;
}

// Destructor
Span::~Span() {
	delete[] this->_array;
};

// Getters
int	Span::at( const size_t i ) const {
	return this->_array[i];
};

size_t	Span::getSize() const {
	return this->_size;
};

// Public Member Functions
void			Span::addNumber( const int num ) {
	if (this->_size >= this->_capacity)
		throw FullException("failed to add '" + std::to_string(num) + "'");
	this->_array[this->_size] = num;
	this->_size++;
};

void	Span::getMinMax( int& min, int& max ) const {
	min = INT_MAX;
	max = INT_MIN;
	for (size_t i = 0; i < this->_size;) {
		if (this->_array[i] < min)
			min = this->_array[i];
		if (this->_array[i] > max)
			max = this->_array[i];
		++i;
	}
};

// For the longest span we only need to know the minimum and maximum
// and calculate the difference
unsigned int	Span::longestSpan() const {
	if (this->_size <= 1)
		throw SpanException("not enough numbers to form a span");
	int	min, max;
	this->getMinMax(min, max);
	long	range = static_cast<long>(max) - static_cast<long>(min);
	if (range == 0)
		throw SpanException("no span found");
	return (unsigned int)range;
};

// For the shortest span we make use of the STL algorithm std::sort which works
// with arryas, vectors and deques. The alogrithm is implemented using the
// Introsort which is a hybrid technique which switches between methods
// depending on input. E.g. if quick sort shows excessive recursion then it may
// switch to Heap Sort.
//
// To use std::sort() to find the shortest span we copy the array into a vector
// then sort then scan the sorted vector for the smallest difference between
// two consecutive values.
unsigned int	Span::shortestSpan() const {
	if (this->_size <= 1)
		throw SpanException("not enough numbers to form a span");
	std::vector<int>	vector_copy(this->_array, this->_array + this->_size);
	std::sort(vector_copy.begin(), vector_copy.end());
	unsigned int	minimum = UINT_MAX;
	unsigned int	diff;
	for (size_t i = 0; i < this->_size - 1;) {
		diff = static_cast<unsigned int>(vector_copy[i + 1] - vector_copy[i]);
		if (diff < minimum)
			minimum = diff;
		++i;
	}
	if (minimum == UINT_MAX)
		throw SpanException("no span found");
	return minimum;
};

void		Span::addRange( const size_t position, int first, int last ) {
	if (position > this->_size)
		throw IndexException("failed to add range: position");
	size_t	range = (size_t)labs(static_cast<long>(first)
			- static_cast<long>(last)) + 1;
	if (range > this->_capacity - this->_size || this->_size == this->_capacity)
		throw FullException("failed to add range");
	bool	increment = first < last ? true : false;
	for (size_t i = position; i < position + range;) {
		if (i < this->_size)
			this->_array[position + range + i] = this->_array[i];
		this->_array[i] = increment ? first + (int)i : first - (int)i;
		++i;
	}
	this->_size += range;
};

// Custom Exceptions
Span::FullException::FullException( const std::string& name ) {
this->_message = name + ": Span object does not have enough space";
};
const char*	Span::FullException::what() const noexcept {
return this->_message.c_str();
};

Span::SpanException::SpanException( const std::string& name ) {
this->_message = name + ": Span find failed";
};
const char*	Span::SpanException::what() const noexcept {
return this->_message.c_str();
};

Span::IndexException::IndexException( const std::string& name ) {
this->_message = name + " out-of-bounds";
};
const char*	Span::IndexException::what() const noexcept {
return this->_message.c_str();
};

std::ostream&	operator<<( std::ostream& out, const Span& in ) {
	for (size_t i = 0; i < in.getSize(); i++) {
		out << in.at(i);
		if (i < in.getSize() - 1)
			out << ", ";
	}
	return out;
};
