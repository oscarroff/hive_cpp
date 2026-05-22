/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:48:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/21 15:58:51 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T, typename C> 
typename MutantStack<T, C>::iterator	MutantStack<T, C>::begin() {
	return this->c.begin();
};

template <typename T, typename C> 
typename MutantStack<T, C>::iterator	MutantStack<T, C>::end() {
	return this->c.end();
};

template <typename T, typename C> 
typename MutantStack<T, C>::const_iterator	MutantStack<T, C>::begin() const {
	return this->c.begin();
};

template <typename T, typename C> 
typename MutantStack<T, C>::const_iterator	MutantStack<T, C>::end() const {
	return this->c.end();
};

template <typename T, typename C> 
typename MutantStack<T, C>::reverse_iterator	MutantStack<T, C>::rbegin() {
	return this->c.rbegin();
};

template <typename T, typename C> 
typename MutantStack<T, C>::reverse_iterator	MutantStack<T, C>::rend() {
	return this->c.rend();
};

template <typename T, typename C> 
typename MutantStack<T, C>::const_reverse_iterator	MutantStack<T, C>::rbegin() const {
	return this->c.rbegin();
};

template <typename T, typename C> 
typename MutantStack<T, C>::const_reverse_iterator	MutantStack<T, C>::rend() const {
	return this->c.rend();
};
