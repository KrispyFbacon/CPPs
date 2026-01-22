/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:05:40 by frbranda          #+#    #+#             */
/*   Updated: 2026/01/22 13:19:11 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> ms;
	
	ms.push(5);
	ms.push(17);
	
	std::cout << "Size: " << ms.size() << ", Top: " << ms.top() << std::endl;
	
	ms.pop();

	std::cout << "Size: " << ms.size() << ", Top: " << ms.top() << std::endl;
	
	
	std::cout << std::endl;

	ms.push(3);
	ms.push(5);
	ms.push(737);
	ms.push(0);
	
	const MutantStack<int>& msRef = ms;
	MutantStack<int>::const_iterator cit = msRef.begin();
	MutantStack<int>::const_iterator cite = msRef.end();

	for (; cit != cite; ++cit)
	{
		cit = 1;
		std::cout << *cit << " ";
	}

	
	MutantStack<int>::iterator it = ms.begin();
	MutantStack<int>::iterator ite = ms.end();
	
	++it;
	--it;
	
	for (; it != ite; ++it)
		std::cout << *it << " ";
	
	std::cout << std::endl;
	
	std::stack<int> s(ms);
	
	return 0;
	
}

// int main(void)
// {
// 	MutantStack<int> stack;

// 	stack.push(5);
// 	stack.push(10);

// 	MutantStack<int>::iterator it = stack.begin();
// 	MutantStack<int>::iterator ite = stack.end();
	
// 	for (; it != ite; ++it)
// 		std::cout << *it << std::endl;
	
// 	return 0;
// }

