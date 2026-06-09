/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 11:47:36 by frbranda          #+#    #+#             */
/*   Updated: 2026/06/09 16:07:01 by frbranda         ###   ########.fr       */
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
	mergeInsertSort(_vector);
}

void PmergeMe::mergeInsertSort(std::vector<int>& arr)
{
	if (arr.size() <=1 )
		return ;
	
	bool hasLeftover = arr.size() % 2 != 0;
	int leftover = hasLeftover ? arr.back() : 0;
	
	// TODO 1) Pairs
	std::vector<int> main;
	std::vector<int> pend;
	std::vector<std::pair<int, int>> pairs;

	// Reserves memory for vectors for performance and no re-size needed!
	size_t halfSize = arr.size() / 2;
	main.reserve(halfSize);
	pend.reserve(halfSize);
	pairs.reserve(halfSize);

	for (size_t i = 0; i < halfSize; ++i)
	{
		int a = arr[2 * i];
		int b = arr[2 * i + 1];
		
		if (a > b)
		{
			main.push_back(a);
			pend.push_back(b);
			pairs.push_back(std::make_pair(b, a));
		}
		else
		{
			main.push_back(b);
			pend.push_back(a);
			pairs.push_back(std::make_pair(a, b));
		}
	}
	
	
	// TODO 2) Main 
	// TODO 3) Pend
	// TODO 4) Binary search 
	// TODO 5) Jacobsthal order

	
	if (arr.size() % 2 != 0)
	{
		// Insert leftover
		//arr.back();
	}
}


/* ========================== Deque Implematation ========================== */

void PmergeMe::sortDeque()
{
	if (_deque.size() <=1 )
		return ;
}