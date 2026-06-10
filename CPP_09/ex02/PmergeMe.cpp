/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 11:47:36 by frbranda          #+#    #+#             */
/*   Updated: 2026/06/10 18:49:19 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc,char** argv) 
{
	for (int i = 1; i < argc; ++i)
	{
		char*	endPtr;
		long	num = std::strtol(argv[i], &endPtr, 10);

		if (*endPtr != '\0')
			throw std::runtime_error("Invalid input argument.");
		if (num <= 0) 
			throw std::invalid_argument("Non positive number.");
		if (num > __INT_MAX__)
			throw std::invalid_argument("Too large number. (INT_MAX limit)");

		_vector.push_back(static_cast<int>(num));
		_deque.push_back(static_cast<int>(num));
	}
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void)other;
}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void)other;
	if (this != &other) {}

	return *this;
}


void PmergeMe::sort()
{
	double	start;

	std::cout << "Before: ";
	printContainer(_vector);

	
	// Vector sort
	start = getTime();
	sortVector();
	double vectorEnd = getTime() - start;
	
	// Deque sort
	start = getTime();
	sortDeque();
	double dequeEnd = getTime() - start;

	
	std::cout << "After: ";
	printContainer(_vector);
	
	std::cout << "Time to process a range of " << _vector.size()
			  << " elements with std::vector : " << vectorEnd << " us\n";
	std::cout << "Time to process a range of " << _deque.size()
			  << " elements with std::deque  : " << dequeEnd << " us"
			  << std::endl;
}



/* ================================ PRIVATE ================================ */


/* ========================== Vector Implematation ========================= */

void PmergeMe::sortVector()
{
	//TODO Make pair fuctions?
	
	mergeInsertSort(_vector);
}

void PmergeMe::mergeInsertSort(std::vector<int>& arr)
{
	if (arr.size() <= 1)
		return ;
	
	// TODO 1) Pairs
	
	std::vector<std::pair<int, int>> pairs;

	// Reserves memory for vectors for performance and no re-size needed!
	size_t halfSize = arr.size() / 2;
	pairs.reserve(halfSize);

	for (size_t i = 0; i < halfSize; ++i)
	{
		int a = arr[2 * i];
		int b = arr[2 * i + 1];
		
		if (a > b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}
	
	mergeInsertSortPairs(pairs);
	
	// TODO 2) Main 
	std::vector<int> winners;
	std::vector<int> losers;
	
	winners.reserve(arr.size());
	losers.reserve(halfSize);

	
	// TODO 3) Pend
	// TODO 4) Binary search 
	// TODO 5) Jacobsthal order

	
	if (arr.size() % 2 != 0)
	{
		// Insert leftover
		//arr.back();
	}
}

// TODO - Instead use int pair vector recursion
void PmergeMe::mergeInsertSortPairs(std::vector<Pair>& pairs)
{
	//TODO EVERYTHING WRONG
	if (pairs.size() <= 1)
		return ;

	std::vector<std::pair<int, int>> winnerPairs;

	size_t	halfSize = pairs.size() / 2;
	winnerPairs.reserve(halfSize);

	for (size_t i = 0; i < halfSize; ++i)
	{
		int a = pairs[2 * i].first;
		int b = pairs[2 * i + 1].first;

		if (a > b)
			winnerPairs()
	}
	

}


/* ========================== Deque Implematation ========================== */

void PmergeMe::sortDeque()
{
	if (_deque.size() <=1 )
		return ;
}