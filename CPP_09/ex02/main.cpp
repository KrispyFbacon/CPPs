/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:05:40 by frbranda          #+#    #+#             */
/*   Updated: 2026/06/08 18:14:43 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/** TODO time of day?
 * 1)
 * std::srand(std::time(NULL));
 * numbs[i] = std::rand() % 100;
 * 
 * 1)
 * struct timeval	tv;
 * 	gettimeofday(&tv, NULL);
 * 	return (tv.tv_sec * 1000000.0 + tv.tv_usec);
 * 
 * 3)
 * std::clock?
 *  */


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Program needs 2 parameters\n";
		std::cerr << "Usage: " << argv[0] 
				  << " < Set of positive numbers with range of INTMAX >"
		<< std::endl;
		return 1;
	}
	
	try
	{
		PmergeMe	pmerge(argc, argv);
		pmerge.sort();
		
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}

