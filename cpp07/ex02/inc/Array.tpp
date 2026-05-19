/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:07:13 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/19 10:18:43 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <stdexcept>
#include <string>

template <typename T> 
class	Array;

// Constructors & Destructors
template <typename T>
Array<T>::Array() : _size(1) {
	this->_array = new T[1]();
};

template <typename T>
Array<T>::Array( const unsigned int n ) : _size(n) {
	this->_array = new T[n]();
};

template <typename T>
Array<T>::Array( const Array& other ) : _size(other._size) {
	this->_array = new T[this->_size];
	for (size_t i = 0; i < this->_size; i++) {
		this->_array[i] = other._array[i];
	}
};

template <typename T>
Array<T>&	Array<T>::operator=( const Array& other ) {
	if (this != &other) {
		delete[] this->_array;
		this->_size = other._size;
		this->_array = new T[this->_size];
		for (size_t i = 0; i < this->_size; i++) {
			this->_array[i] = other._array[i];
		}
	}
	return *this;
};

template <typename T>
Array<T>::~Array() {
	delete[] this->_array;
};

// Public Member Functions
template <typename T>
T&			Array<T>::operator[]( size_t index ) {
	if (index >= this->_size)
		throw std::out_of_range("array["
			+ std::to_string(index)
			+ "] does not point to a valid address in memory. Valid indexes: 0-"
			+ std::to_string(this->_size));
	return this->_array[index];
};

template <typename T>
const T&	Array<T>::operator[]( size_t index ) const {
	if (index >= this->_size)
		throw std::out_of_range("array["
			+ std::to_string(index)
			+ "] does not point to a valid address in memory. Valid indexes: 0-"
			+ std::to_string(this->_size));
	return this->_array[index];
};

template <typename T>
size_t		Array<T>::size() { return this->_size; };
