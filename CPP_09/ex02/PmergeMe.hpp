/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 11:47:28 by frbranda          #+#    #+#             */
/*   Updated: 2026/06/05 12:12:03 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <ctime>

#include <vector>
#include <deque>

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		~PmergeMe();

		PmergeMe& operator=(const PmergeMe& other);

		void sortVector();
		void sortDeque();
};

#endif