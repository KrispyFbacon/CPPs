/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 11:47:28 by frbranda          #+#    #+#             */
/*   Updated: 2026/06/08 18:36:47 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <stdexcept>

#include <vector>
#include <deque>

const bool SHORT_PRINT = true;
const int MAX_PRINT = 10;

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
		
		void sortVector();
		void sortDeque();

		PmergeMe();
	public:
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& other);
		~PmergeMe();
		
		PmergeMe& operator=(const PmergeMe& other);
		
		void sort();

		template <typename T>
			void printContainer(const T& container) const;
};

#endif