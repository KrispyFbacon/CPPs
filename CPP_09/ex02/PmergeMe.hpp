/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 11:47:28 by frbranda          #+#    #+#             */
/*   Updated: 2026/07/15 13:31:29 by frbranda         ###   ########.fr       */
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
		typedef std::vector<int>::iterator itVec;
		typedef std::pair<int,int>	Pair;
		typedef std::vector<Pair>::const_iterator	pairVectorIt;
		typedef std::deque<Pair>::const_iterator	pairDequeIt;
		
		std::vector<int> _vector;
		std::deque<int> _deque;
		
		// Vector Implematation
		void	_sortVector();
		void	_mergeSortPairs(std::vector<Pair>& pairs, size_t left, size_t right);
		void	_mergePairs(std::vector<Pair>& pairs, size_t left, size_t mid, size_t right);
		void	_binaryInsert(std::vector<int> &arr,int value, size_t end);
		size_t	_binarySearch(const std::vector<int> &arr, int value, size_t end);
		
		// Deque Implematation
		void sortDeque();
		void mergeInsertSort(std::deque<int>& arr);

		// Jacobsthal number sequence
		std::vector<size_t> generateJacobsthal(size_t max);

		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		
	public:
		PmergeMe(int argc, char** argv);
		~PmergeMe();
		
		void sort();
};

#endif