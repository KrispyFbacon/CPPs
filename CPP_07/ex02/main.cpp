/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:55:53 by frbranda          #+#    #+#             */
/*   Updated: 2026/01/15 15:31:48 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_NUM 40

void test1_void()
{
	std::cout << BOLD_C << "=== TEST 1: Empty Array ===" << RST << std::endl;
	
	Array<int> empty;
	
	std::cout << BOLD_Y << "Empty array size: " << RST << empty.size() << std::endl;
	try
	{
		empty[0] = 42;
	}
	catch (const std::out_of_range& e)
	{
		std::cout << RED << "Exception caught correctly: " << RST << e.what() << std::endl;
	}
	
	std::cout << std::endl;
}

void test2_int()
{
	std::cout << BOLD_C << "\n=== TEST 2: Int Array ===" << RST << std::endl;

	Array<int> numbs(MAX_NUM);
	
	std::cout << BOLD_Y << "Number of elements: " << RST << numbs.size() << std::endl;
	std::cout << BOLD_M << "Original: " << RST << std::endl;
	for (unsigned int i = 0; i < numbs.size(); ++i)
	{
		numbs[i] = std::rand() % 100;
		std::cout << numbs[i] << " ";
	}
	
	std::cout << std::endl;
	
	
	std::cout << BOLD_M << "\nCopy Constructor Test: " << RST << std::endl;
	
	Array<int> copyNumbs(numbs);
	
	for (unsigned int i = 0; i < copyNumbs.size(); ++i)
	{
		std::cout << copyNumbs[i] << " ";
		if (copyNumbs[i] != numbs[i])
		{
			std::cerr << "\nERROR: Different values in copy!" << std::endl;
			return;
		}
	}
	
	std::cout << std::endl;
	
	
	std::cout << BOLD_M << "\nAssignment Operator Test: " << RST << std::endl;
	
	Array<int> numbsAssign(5);
	
	std::cout << BOLD_Y << "Size before assignment: " << RST << numbsAssign.size() << std::endl;
	numbsAssign = numbs;
	std::cout << BOLD_Y << "Size after assignment: " << RST << numbsAssign.size() << std::endl;
	
	std::cout << BOLD_M << "Assigned array: " << RST << std::endl;
	for (unsigned int i = 0; i < numbsAssign.size(); ++i)
	{
		std::cout << numbsAssign[i] << " ";
		if (numbsAssign[i] != numbs[i])
		{
			std::cerr << "\nERROR: Different values after assignment!" << std::endl;
			return;
		}
	}
	
	std::cout << "\n" << std::endl;
}

void test3_string()
{
	std::cout << BOLD_C << "\n=== TEST 3: String Array ===" << RST << std::endl;
	Array<std::string> strArray(3);
	
	std::cout << BOLD_Y << "Number of elements: " << RST << strArray.size() << std::endl;
	
	strArray[0] = "Hello";
	strArray[1] = "I'm";
	strArray[2] = "Bacon";
	
	std::cout << BOLD_M << "String array contents: " << RST << std::endl;
	for (unsigned int i = 0; i < strArray.size(); ++i)
	{
		std::cout << i << ": " << strArray[i] << std::endl;
	}
	
	
	try
	{
		std::cout << BOLD_M << "\nTrying to access index 10..." << RST << std::endl;
		strArray[10] = "Out of bounds";
	}
	catch (const std::out_of_range& e) 
	{
		std::cout << RED << "Exception caught correctly: " << RST << e.what() << std::endl;
	}
	
	std::cout << std::endl;
}

void test4_const()
{
	std::cout << BOLD_C << "\n=== TEST 4: Const String Array ===" << RST << std::endl;
	
	Array<std::string> strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "!";
	
	const Array<std::string> constStrArray(strArray);
	
	std::cout << BOLD_Y << "Const string array size: " << RST << constStrArray.size() << std::endl;
	std::cout << BOLD_M << "Const string array contents: " << RST << std::endl;
	for (unsigned int i = 0; i < constStrArray.size(); ++i)
	{
		std::cout << constStrArray[i] << " ";
	}
	
	//constStrArray[0] = "Can't compile";

	std::cout << "\n" << std::endl;
}

int main()
{
	std::srand(std::time(NULL));
	
	test1_void();
	test2_int();
	test3_string();
	test4_const();
	
	return 0;
}