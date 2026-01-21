/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:05:40 by frbranda          #+#    #+#             */
/*   Updated: 2026/01/21 15:14:23 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define MAX_NUM 10000


// ==== TEST 1 ====
void test1_Default()
{
	std::srand(std::time(NULL));

	std::vector<int> arr;
	
	for (unsigned int i = 0; i < MAX_NUM; ++i)
	{
		arr.push_back(std::rand() % MAX_NUM);
		//arr.push_back(i);
		std::cout << arr[i] << " ";
	}
	
	std::cout << "\n" << std::endl;

	Span sp = Span(MAX_NUM);

	try
	{
		sp.addRange(arr.begin(), arr.end());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}


// ==== TEST 2 ====
void test2_ManualInsertion()
{
	Span sp(MAX_NUM);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addRange(1, 10);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
}

int main(void)
{
	test1_Default();
	test2_ManualInsertion();
	
	return 0;
}

