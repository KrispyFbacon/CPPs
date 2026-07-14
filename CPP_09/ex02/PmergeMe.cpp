/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 11:47:36 by frbranda          #+#    #+#             */
/*   Updated: 2026/07/14 19:30:11 by frbranda         ###   ########.fr       */
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

void PmergeMe::_sortVector()
{
	if (_vector.size() <= 1)
		return ;
	
	// TODO 1) Pairs
	std::vector<std::pair<int, int>> pairs;

	// Reserves memory for vectors for performance and no re-size needed!
	size_t halfSize = _vector.size() / 2;
	pairs.reserve(halfSize);

	for (size_t i = 0; i < halfSize; ++i)
	{
		int a = _vector[2 * i];
		int b = _vector[2 * i + 1];
		
		if (a > b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}
	
	// TODO 2) Winner sort
	_mergeSortPairs(pairs, 0, pairs.size());
	
	// TODO 3) Binary search 
	std::vector<int> mainChain;

	for (size_t i = 0; i < halfSize; ++i)
		mainChain.push_back(pairs[i].first);


 	// TODO 4) Jacobsthal order
	std::vector<size_t> jacob = generateJacobsthal(halfSize);
	
	size_t lastIdx = 1;
	for (size_t i; i < jacob.size(); ++i)
	{
		size_t current = std::min(jacob[i], halfSize);
		
		for (size_t j = current; j >= lastIdx; --j)
		{
			_binaryInsert();
		}

		lastIdx = current;
	}

	//if (arr.size() % 2 != 0)
	// 	{
	// 		// Insert leftover
	// 		//arr.back();
	// 	}
}

void PmergeMe::_mergeSortPairs(std::vector<Pair>& pairs, size_t left, size_t right)
{
	if (right - left <= 1)
		return;

	size_t mid = left + (right - left) / 2;

	_mergeSortPairs(pairs, left, mid);
	_mergeSortPairs(pairs, mid, right);
	_mergePairs(pairs, left, mid, right);
}

void PmergeMe::_mergePairs(std::vector<Pair>& pairs, size_t left, size_t mid, size_t right)
{
	std::vector<Pair> temp;
	pairs.reserve(right - left);

	size_t i = left;
	size_t j = mid;

	while ( i < mid && j < right )
	{
		if (pairs[i].first < pairs[j].first)
			temp.push_back(pairs[i++]);
		else 
			temp.push_back(pairs[j++]);
	}

	while (i < mid)
		temp.push_back(pairs[i++]);
	while (j < right)
		temp.push_back(pairs[j++]);

	for (size_t k = 0; k < temp.size(); ++i)
		pairs[left + k] = temp[k];
}

void PmergeMe::_binaryInsert(std::vector<int> &arr,int value, size_t end)
{
	// size_t end = findWinner(mainChain, pairs[i].first);

	// binaryInsertVector(mainChain, pairs[i].second, end);
	
	size_t pos = _binarySearch(arr, value, end);
	arr.insert(arr.begin() + pos, value);
}

size_t PmergeMe::_binarySearch(const std::vector<int> &arr, int value, size_t end)
{
	
}

/* ========================== Deque Implematation ========================== */

void PmergeMe::sortDeque()
{
	if (_deque.size() <=1 )
		return ;
}

std::vector<size_t> PmergeMe::generateJacobsthal(size_t max)
{
	std::vector<size_t> jacob;

	if (max <= 0)
		return jacob;

	jacob.push_back(1);
	if (max < 3)
		return jacob;

	jacob.push_back(3);

	while (jacob.back() < max)
	{
		size_t n = jacob.size();
		jacob.push_back(jacob[n - 1] + 2 * jacob[n - 2]);
	}

	return jacob;
}