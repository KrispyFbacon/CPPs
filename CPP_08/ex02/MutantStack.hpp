/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:18:41 by frbranda          #+#    #+#             */
/*   Updated: 2026/02/19 14:11:29 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		~MutantStack();

		MutantStack& operator=(const MutantStack& other);


		// typedefs
		typedef typename MutantStack<T>::container_type			container_type;
		
		typedef typename container_type::iterator				iterator;
		typedef typename container_type::const_iterator			const_iterator;
		typedef typename container_type::reverse_iterator		reverse_iterator;
		typedef typename container_type::const_reverse_iterator	const_reverse_iterator;


		// std::stack data is stored in a protected member 'c'
		iterator begin();
		iterator end();
		
		const_iterator begin() const;
		const_iterator end() const;

		reverse_iterator rbegin();
		reverse_iterator rend();
		
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

#endif
