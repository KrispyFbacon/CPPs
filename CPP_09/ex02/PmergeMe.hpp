/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 11:47:28 by frbranda          #+#    #+#             */
/*   Updated: 2026/07/18 18:21:09 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include "Utils.hpp"

class PmergeMe
{
	private:
		typedef std::vector<int>::iterator itVec;
		typedef std::deque<int>::iterator itDeq;
		typedef std::pair<int,int>	Pair;
		
		std::vector<int> _vector;
		std::deque<int> _deque;
		
		
		// Vector Implematation
		void	_sortVector();
		void	_mergeSortPairs(std::vector<Pair>& pairs, size_t left, size_t right);
		void	_mergePairs(std::vector<Pair>& pairs, size_t left, size_t mid, size_t right);
		void	_binaryInsert(std::vector<int> &arr,int value, size_t end);
		size_t	_binarySearch(const std::vector<int> &arr, int value, size_t end);
		
		// Deque Implematation
		void	_sortDeque();
		void	_mergePairs(std::deque<Pair>& pairs, size_t left, size_t mid, size_t right);
		void	_mergeSortPairs(std::deque<Pair>& pairs, size_t left, size_t right);
		void	_binaryInsert(std::deque<int>& arr, int value, size_t end);
		size_t	_binarySearch(const std::deque<int>& arr, int value, size_t end);

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