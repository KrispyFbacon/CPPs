/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:18:41 by frbranda          #+#    #+#             */
/*   Updated: 2026/01/21 17:43:28 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <queue>

template <typename C>
class MutantStack : public std::stack<C>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		~MutantStack();

		MutantStack& operator=(const MutantStack& other);

		typedef typename MutantStack<C>::container_type::iterator iterator;
		typedef typename MutantStack<C>::container_type::const_iterator const_iterator;
		typedef typename MutantStack<C>::container_type::reverse_iterator reverse_iterator;
		typedef typename MutantStack<C>::container_type::const_reverse_iterator const_reverse_iterator;
		
		iterator begin();
		iterator end();
		
		const_iterator begin() const;
		const_iterator end() const;

		reverse_iterator rbegin();
		reverse_iterator rend();
		
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
};

// template <typename T, typename Container = std::deque<T> >

// template <typename C>
// class MutantStack
// {
// 	private:
// 		C*	container;
		
// 	public:
// 		MutantStack();
// 		MutantStack(const MutantStack& other);
// 		~MutantStack();

// 		MutantStack& operator=(const MutantStack& other);

// 		typename MutantSack<C>::itterator begin(); // or C::itterator begin();
// 		typename MutantSack<C>::itterator end();
		
// 		typename MutantSack<C>::const_itterator begin() const;
// 		typename MutantSack<C>::const_itterator end() const;

// 		typename MutantSack<C>::reverse_iterator rbegin();
// 		typename MutantSack<C>::reverse_iterator rend();
		
// 		typename MutantSack<C>::const_reverse_iterator rbegin() const;
// 		typename MutantSack<C>::const_reverse_iterator rend() const;

// 		typename MutantSack<C>::itterator& operator++();
// 		typename MutantSack<C>::itterator& operator--();
// };

#endif