/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:48:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/21 15:57:30 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <deque>

template <typename T, typename C = std::deque<T> >
class   MutantStack : public std::stack<T, C> {
private:
public:
	// Constructors & Destructors
	MutantStack() = default;
	MutantStack( const MutantStack &other ) = default;
	MutantStack &operator=( const MutantStack &other ) = default;
	~MutantStack() = default;

	// Aliases
	using iterator = typename C::iterator;
	using const_iterator = typename C::const_iterator;
	using reverse_iterator = typename C::reverse_iterator;
	using const_reverse_iterator = typename C::const_reverse_iterator;

	// Forward Iterators
	iterator		begin();
	iterator		end();
	const_iterator	begin() const;
	const_iterator	end() const;
	
	// Reverse Iterators
	reverse_iterator		rbegin();
	reverse_iterator		rend();
	const_reverse_iterator	rbegin() const;
	const_reverse_iterator	rend() const;
};
