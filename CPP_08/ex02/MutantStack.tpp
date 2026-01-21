/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:18:53 by frbranda          #+#    #+#             */
/*   Updated: 2026/01/21 18:01:10 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename C>
MutantStack<C>::MutantStack() : std::stack<C>() {}

template <typename C>
MutantStack<C>::MutantStack(const MutantStack& other) : std::stack<C>(other) {}

template <typename C>
MutantStack<C>::~MutantStack() {}

template <typename C>
MutantStack<C>& MutantStack<C>::operator=(const MutantStack& other)
{
	if (this != &other)
		std::stack<c>::operator=(other);

	return *this;
}


template <typename C>
MutantStack<C>::iterator MutantStack<C>::begin()
{
	return (this->c.begin());
}

template <typename C>
MutantStack<C>::iterator MutantStack<C>::end()
{
	return (this->c.end());
}


// const
template <typename C>
MutantStack<C>::const_iterator MutantStack<C>::begin() const
{
	return (this->c.begin());
}

template <typename C>
MutantStack<C>::const_iterator MutantStack<C>::end() const
{
	return (this->c.end());
}


// reverse 
template <typename C>
MutantStack<C>::reverse_iterator MutantStack<C>::rbegin()
{
	return (this->c.rbegin());
}

template <typename C>
MutantStack<C>::reverse_iterator MutantStack<C>::rend()
{
	return (this->c.rend());
}


//reverse conts
template <typename C>
MutantStack<C>::const_reverse_iterator MutantStack<C>::rbegin() const
{
	return (this->c.rbegin());
}

template <typename C>
MutantStack<C>::const_reverse_iterator MutantStack<C>::rend() const
{
	return (this->c.rend());
}

