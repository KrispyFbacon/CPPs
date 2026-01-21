/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:05:40 by frbranda          #+#    #+#             */
/*   Updated: 2026/01/16 18:04:50 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>
#include <vector>
#include <algorithm> // std::stort
#include <numeric> // std::adjacent_difference
#include <ctime>
#include <cstdlib>

#define MAX_NUM 20

int main(void)
{
	std::srand(std::time(NULL));

	std::vector<int> arr;
	
	for (unsigned int i = 0; i < MAX_NUM; ++i)
	{
		arr.push_back(std::rand() % 100);
		std::cout << arr[i] << " ";
	}

	std::cout << "\n" << std::endl;

	std::sort(arr.begin(), arr.end());
	
	for (unsigned int i = 0; i < MAX_NUM; ++i)
	{
		std::cout << arr[i] << " ";
	}
	
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::adjacent_difference(arr.begin(), arr.end(), arr.begin());

	for (unsigned int i = 0; i < MAX_NUM; ++i)
	{
		std::cout << arr[i] << " ";
	}
		
	std::cout << std::endl;

	return 0;
}

