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

/*
* We are creating a mutant version of stack that can be used with iterators.
* The functionality actually already exists in the codebase as std::stack
* inherits from std::deque which itself uses iterators. But the std::stack
* child template class does not give access to them. So to get back iterator
* functionality we need to reveal the base class.
*
* This is done in two stages:
* 1.	We create aliases for the data types (iterator, const it, reverse it
*		etc.) via a template typename that can access the std::deque class.
* 2.	We then create member functions in the mutant child class that act as
*		wrappers for the std::deque member functions that return iterators
*		such as begin(), rend() etc.
*		These are accessible via the Container c that is inherited from the
*		std::deque's protected member variables.
*/

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
