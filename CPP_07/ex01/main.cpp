/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:55:53 by frbranda          #+#    #+#             */
/*   Updated: 2026/01/14 15:42:44 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void test1_int()
{
	// === Array int ===
	std::cout << " === INT === "  << std::endl;

	int nums[] = {1, 2, 3, 4, 5};
	int sizeNums = sizeof(nums) / sizeof(nums[0]);

	iter(nums, sizeNums, print);
	iter(nums, sizeNums, increment);

	std::cout << std::endl;

	iter2(nums, sizeNums, print<int>);
	iter2(nums, sizeNums, increment<int>);

	std::cout << std::endl;
	
	iter(nums, sizeNums, print);

	std::cout << std::endl;
}


void test2_char()
{
	// === Array char ===
	std::cout << "\n === CHAR === "  << std::endl;
	
	char chars[] = {'a', 'b', 'c', 48, '1'};
	int sizeChars = sizeof(chars) / sizeof(chars[0]);

	iter(chars, sizeChars, print);
	iter(chars, sizeChars, increment);

	std::cout << std::endl;
	
	iter2(chars, sizeChars, print<char>);
	iter2(chars, sizeChars, increment<char>);

	std::cout << std::endl;
	
	iter(chars, sizeChars, print);
	
	std::cout << std::endl;
}


void test3_string()
{
	// === Array str ===
	std::cout << "\n === STRING === "  << std::endl;
	
	std::string strs[] = {"Hello", "my", "name", "is", "Bacon"};
	int sizeStrs = sizeof(strs) / sizeof(strs[0]);

	iter(strs, sizeStrs, print);

	std::cout << std::endl;

	iter2(strs, sizeStrs, print<std::string>);
}

int main()
{
	test1_int();
	test2_char();
	test3_string();

	return 0;
}