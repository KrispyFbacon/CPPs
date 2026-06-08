/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:08:41 by frbranda          #+#    #+#             */
/*   Updated: 2026/06/08 18:35:57 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
void PmergeMe::printContainer(const T& container) const
{
	if (SHORT_PRINT)
	{
		int count = 0; 
		for (typename T::const_iterator it = container.begin();
			it != container.end() && count < MAX_PRINT;
			++it)
		{
			std::cout << *it << " ";
			count++;
		}
		if (container.size() > MAX_PRINT)
			std::cout << "[...]";

	}
	else
	{
		for ( typename T::const_iterator it = container.begin(); 
				it != container.end(); ++it)
			std::cout << *it << " ";
	}
	
	std::cout << std::endl;
}