/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 11:47:28 by frbranda          #+#    #+#             */
/*   Updated: 2026/06/09 15:37:16 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include "Utils.hpp"

const bool SHORT_PRINT = true;
const int MAX_PRINT = 10;

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
		
		// Vector Implematation
		void sortVector();
		void mergeInsertSort(std::vector<int>& arr);
		
		// Deque Implematation
		void sortDeque();
		void mergeInsertSort(std::deque<int>& arr);

		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		
	public:
		PmergeMe(int argc, char** argv);
		~PmergeMe();
		
		void sort();
};

#endif