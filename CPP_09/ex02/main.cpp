/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:05:40 by frbranda          #+#    #+#             */
/*   Updated: 2026/06/09 14:59:41 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Binary search ⌈log₂(N+1)⌉


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Error: Program needs at least 1 argument\n";
		std::cerr << "Usage: " << argv[0] 
				  << " < Set of positive numbers with range of INTMAX >"
		<< std::endl;
		return 1;
	}
	
	try
	{
		PmergeMe	pmerge(argc, argv);
		pmerge.sort();
		
		// std::vector<int> vec = pmerge.getVector();
		// printContainer(vec);
		// std::cout << std::is_sorted(vec.begin(), vec.end()) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}

