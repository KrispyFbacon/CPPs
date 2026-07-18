/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 11:47:36 by frbranda          #+#    #+#             */
/*   Updated: 2026/07/18 18:23:29 by frbranda         ###   ########.fr       */
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

		int n = static_cast<int>(num);
		if (std::find(_vector.begin(), _vector.end(), n) != _vector.end())
			throw std::invalid_argument("Duplicate number.");

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
	std::cout << std::endl;

	
	// Vector sort
	start = getTime();
	_sortVector();
	double vectorEnd = getTime() - start;
	
	// Deque sort
	start = getTime();
	_sortDeque();
	double dequeEnd = getTime() - start;

	
	std::cout << "After: ";
	printContainer(_vector);
	std::cout << std::endl;
	
	std::cout << std::fixed << std::setprecision(5);
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
	
	// 1) Pairs
	std::vector<Pair> pairs;

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
	
	
	// Order Winners
	_mergeSortPairs(pairs, 0, pairs.size());
	
	std::vector<int> mainChain;
	mainChain.reserve(_vector.size());

	for (size_t i = 0; i < halfSize; ++i)
		mainChain.push_back(pairs[i].first);


		
	// Jacobsthal binary insert
	std::vector<size_t> jacob = generateJacobsthal(halfSize);
	
	size_t lastIdx = 1;
	for (size_t i = 0; i < jacob.size(); ++i)
	{
		size_t currentIdx = std::min(jacob[i], halfSize);
		
		for (size_t j = currentIdx; j >= lastIdx; --j)
		{
			size_t idx = j - 1; // 0-based pend index

			itVec it = std::find(mainChain.begin(), mainChain.end(), pairs[idx].first);
			size_t bound = it - mainChain.begin() + 1;

			_binaryInsert(mainChain, pairs[idx].second, bound);
		}

		lastIdx = currentIdx + 1; // Next Jacobsthal block
	}

	
	// Leftover insert
	if (_vector.size() % 2 != 0)
		_binaryInsert(mainChain, _vector.back(), mainChain.size());

	_vector = mainChain;
}

 // position o the pair
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
	temp.reserve(right - left);

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

	for (size_t k = 0; k < temp.size(); ++k)
		pairs[left + k] = temp[k];
}

// Basiccally std::lower_bound
size_t PmergeMe::_binarySearch(const std::vector<int>& arr, int value, size_t end)
{
	size_t low = 0;
	size_t high = end;

	while (low < high)
	{
		size_t mid = low + (high - low) / 2;
		if (arr[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

void PmergeMe::_binaryInsert(std::vector<int>& arr, int value, size_t end)
{
	size_t pos = _binarySearch(arr, value, end);
	arr.insert(arr.begin() + pos, value);
}







/* ========================== Deque Implematation ========================== */

void PmergeMe::_sortDeque()
{
	if (_deque.size() <= 1)
		return ;
	
	// 1) Pairs
	std::deque<Pair> pairs;

	
	size_t halfSize = _deque.size() / 2;

	for (size_t i = 0; i < halfSize; ++i)
	{
		int a = _deque[2 * i];
		int b = _deque[2 * i + 1];
		
		if (a > b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}
	
	
	// Order Winners
	_mergeSortPairs(pairs, 0, pairs.size());
	
	std::deque<int> mainChain;

	for (size_t i = 0; i < halfSize; ++i)
		mainChain.push_back(pairs[i].first);


		
	// Jacobsthal binary insert
	std::vector<size_t> jacob = generateJacobsthal(halfSize);
	
	size_t lastIdx = 1;
	for (size_t i = 0; i < jacob.size(); ++i)
	{
		size_t currentIdx = std::min(jacob[i], halfSize);
		
		for (size_t j = currentIdx; j >= lastIdx; --j)
		{
			size_t idx = j - 1; // 0-based pend index

			itDeq it = std::find(mainChain.begin(), mainChain.end(), pairs[idx].first);
			size_t bound = it - mainChain.begin() + 1;

			_binaryInsert(mainChain, pairs[idx].second, bound);

		}

		lastIdx = currentIdx + 1; // Next Jacobsthal block
	}

	
	// Leftover insert
	if (_deque.size() % 2 != 0)
		_binaryInsert(mainChain, _deque.back(), mainChain.size());

	_deque = mainChain;
}

 // position o the pair
void PmergeMe::_mergeSortPairs(std::deque<Pair>& pairs, size_t left, size_t right)
{
	if (right - left <= 1)
		return;

	size_t mid = left + (right - left) / 2;

	_mergeSortPairs(pairs, left, mid);
	_mergeSortPairs(pairs, mid, right);
	_mergePairs(pairs, left, mid, right);
}

void PmergeMe::_mergePairs(std::deque<Pair>& pairs, size_t left, size_t mid, size_t right)
{
	std::deque<Pair> temp;

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

	for (size_t k = 0; k < temp.size(); ++k)
		pairs[left + k] = temp[k];
}


void PmergeMe::_binaryInsert(std::deque<int>& arr, int value, size_t end)
{
	size_t pos = _binarySearch(arr, value, end);
	arr.insert(arr.begin() + pos, value);
}

// Basiccally std::lower_bound
size_t PmergeMe::_binarySearch(const std::deque<int>& arr, int value, size_t end)
{
	size_t low = 0;
	size_t high = end;

	while (low < high)
	{
		size_t mid = low + (high - low) / 2;
		if (arr[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}





/* =============================== JACOBSTHAL ============================== */

std::vector<size_t> PmergeMe::generateJacobsthal(size_t max)
{
	std::vector<size_t> jacob;

	if (max == 0)
		return jacob;

	jacob.push_back(1);
	
	while (jacob.back() < max)
	{
		size_t n = jacob.size();
		size_t next = (n == 1) ? 3 : jacob[n - 1] + 2 * jacob[n - 2];
		jacob.push_back(next);
	}
	return jacob;
}






/* =============================== DEBUGGING =============================== */



/*
 * Attempted to compute the binary-search bound in O(1) using the
 * Jacobsthal insertion order.
 *
 * Several formulas were tested:
 *   - idx + (lastIdx - 1)
 *   - idx + (lastIdx - 1) + insertedThisBatch
 *   - idx + totalInserted
 *
 * While some passed extensive manual tests, I could not prove the
 * formula correct for every input. To guarantee correctness, the
 * implementation below finds the current position of the winner pair
 * and searches only up to that position.
 */

// void PmergeMe::_sortVector()
// {
// 	if (_vector.size() <= 1)
// 		return ;
	
// 	// TODO 1) Pairs
// 	std::vector< std::pair<int, int> > pairs;

// 	// Reserves memory for vectors for performance and no re-size needed!
// 	size_t halfSize = _vector.size() / 2;
// 	pairs.reserve(halfSize);

// 	for (size_t i = 0; i < halfSize; ++i)
// 	{
// 		int a = _vector[2 * i];
// 		int b = _vector[2 * i + 1];
		
// 		if (a > b)
// 			pairs.push_back(std::make_pair(a, b));
// 		else
// 			pairs.push_back(std::make_pair(b, a));
// 	}
	
// 	// Order Winners
// 	_mergeSortPairs(pairs, 0, pairs.size());
	
// 	std::vector<int> mainChain;
// 	mainChain.reserve(_vector.size());

// 	for (size_t i = 0; i < halfSize; ++i)
// 		mainChain.push_back(pairs[i].first);

	
// 	// Jacobsthal binary insert
// 	std::vector<size_t> jacob = generateJacobsthal(halfSize);
	

// 	size_t lastIdx = 1;
// 	size_t totalInserted = 0;

// 	for (size_t i = 0; i < jacob.size(); ++i)
// 	{
// 		size_t currentIdx = std::min(jacob[i], halfSize);

// 		std::cout << "\n========== Jacobsthal Batch ==========\n";
// 		std::cout << "lastIdx       : " << lastIdx << '\n';
// 		std::cout << "currentIdx    : " << currentIdx << '\n';
// 		std::cout << "totalInserted : " << totalInserted << '\n';

// 		for (size_t j = currentIdx; j >= lastIdx; --j)
// 		{
// 			size_t idx = j - 1;
// 			size_t bound = idx + totalInserted;

// 			std::cout << "\nInserting loser b" << j << '\n';
// 			std::cout << "idx            : " << idx << '\n';
// 			std::cout << "winner         : " << pairs[idx].first << '\n';
// 			std::cout << "loser          : " << pairs[idx].second << '\n';
// 			std::cout << "bound          : " << bound << '\n';
// 			std::cout << "totalInserted  : " << totalInserted << '\n';

// 			std::cout << "Main chain before: ";
// 			printContainer(mainChain);

// 			_binaryInsert(mainChain, pairs[idx].second, bound);

// 			++totalInserted;

// 			std::cout << "Main chain after : ";
// 			printContainer(mainChain);

// 			std::cout << "totalInserted now: " << totalInserted << '\n';

// 			if (j == lastIdx)
// 				break;
// 		}

// 		lastIdx = currentIdx + 1;
// 	}
	
// 	//Leftover insert
// 	if (_vector.size() % 2 != 0)
// 		_binaryInsert(mainChain, _vector.back(), mainChain.size());

// 	_vector = mainChain;

// }
