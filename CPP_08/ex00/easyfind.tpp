/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:47:53 by frbranda          #+#    #+#             */
/*   Updated: 2026/01/21 12:25:21 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/* =========================== Iterator Version ============================ */
template <typename T>
typename T::iterator	easyfind(T& container, int target)
{
	typename T::iterator it = std::find(container.begin(), container.end(), target);
	
	if (it == container.end())
		throw std::runtime_error("Occurrence not found!");
			
	return it;
}


/* ======================== Const Iterator Version ========================= */
template <typename T>
typename T::const_iterator	easyfind(const T& container, int target)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), target);
	
	if (it == container.end())
			throw std::runtime_error("Occurrence not found!");
	
	return it;
}


// /* ======================= Reverse Iterator Version ======================== */

// template <typename T>
// typename T::iterator	easyfind(T& container, int target)
// {
// 	typename T::reverse_iterator rit = std::find(container.rbegin(), container.rend(), target);
	
// 	if (rit == container.rend())
// 		throw std::runtime_error("Occurrence not found!");
			
// 	return (--(rit.base()));
// }