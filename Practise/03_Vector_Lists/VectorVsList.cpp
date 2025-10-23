/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorVsList.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:00:55 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/23 13:03:01 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::vector<int> v = {1, 2, 3};
	std::list<int> l = {1, 2, 3};

	// Access
	std::cout << v[1] << std::endl; // O(1)
	// std::cout << l[1]; // ERROR: no operator[]

	// Insert
	v.insert(v.begin() + 1, 10); // O(n)
	auto it = l.begin();
	std::advance(it, 1);
	l.insert(it, 10); // O(1)

	return 0;
}