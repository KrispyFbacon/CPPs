/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 11:47:36 by frbranda          #+#    #+#             */
/*   Updated: 2026/06/08 18:43:17 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc,char** argv) 
{
	if (argc < 2)
		throw std::runtime_error("Program needs at least 2 Arguments.");

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
	//TODO
	std::cout << "Before: ";
	printContainer(_vector);

	//timeStart
	sortVector();
	double vectorTime;
	//timeEnd
	
	//timeStart
	sortDeque();
	double dequeTime;
	//timeEnd

	std::cout << "After: ";
	printContainer(_vector);
	
	std::cout << "Time to process a range of " << _vector.size()
			  << " elements with std::vector : " << vectorTime << " us\n";
	std::cout << "Time to process a range of " << _deque.size()
			  << " elements with std::deque  : " << dequeTime << " us"
			  << std::endl;
}

template <typename T>
void PmergeMe::printContainer(const T& container) const
{
	for (size_t i = 0; i < container.size)
	std::cout << std::endl;
}



/* ================================= PRIVATE =============================== */

void PmergeMe::sortVector()
{
	
}

void PmergeMe::sortDeque()
{
	
}