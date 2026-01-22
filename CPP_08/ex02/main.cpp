/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:05:40 by frbranda          #+#    #+#             */
/*   Updated: 2026/01/22 16:00:07 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

# define BOLD_Y		"\033[1;33m"
# define RST	"\033[0m"

void Title (const std::string& title)
{
	std::cout << BOLD_Y << "\n--- " << title << " ---" << RST << std::endl;
}

int main()
{
	MutantStack<int> ms;
	
	ms.push(5);
	ms.push(17);
	
	std::cout << "Size: " << ms.size() << ", Top: " << ms.top() << std::endl;
	
	ms.pop();

	std::cout << "Size: " << ms.size() << ", Top: " << ms.top() << std::endl;

	ms.push(3);
	ms.push(5);
	ms.push(737);
	ms.push(0);

	
	
	/*  ======= Const Iterators =======  */
	
	Title ("Const Iterators");
	const MutantStack<int>& msRef = ms;
	MutantStack<int>::const_iterator cit = msRef.begin();
	MutantStack<int>::const_iterator cite = msRef.end();
	MutantStack<int>::const_reverse_iterator rcit = msRef.rbegin();
	MutantStack<int>::const_reverse_iterator rcite = msRef.rend();

	for (; cit != cite; ++cit)
	{
		//*cit *= 10;
		std::cout << *cit << " ";
	}
	std::cout << std::endl;

	for (; rcit != rcite; ++rcit)
		std::cout << *rcit << " ";
	std::cout << std::endl;
	
	
	
	/*  ======= Iterators =======  */
	
	Title ("Iterators");
	MutantStack<int>::iterator it = ms.begin();
	MutantStack<int>::iterator ite = ms.end();
	MutantStack<int>::reverse_iterator rit = ms.rbegin();
	MutantStack<int>::reverse_iterator rite = ms.rend();
	
	++it;
	--it;
	
	for (; it != ite; ++it)
	{
		*it *= 10;
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	for (; rit != rite; ++rit)
		std::cout << *rit << " ";
	std::cout << std::endl;
	

	
	/*  ======= Compare =======  */

	Title ("Compare");
	std::stack<int> s(ms);
	
	std::cout << "Size: " << ms.size() << ", Top: " << ms.top() << std::endl;
	std::cout << "Size: " << s.size() << ", Top: " << s.top() << std::endl;
	
	
	
	/*  ======= Copy Constructor =======  */
	
	Title ("Copy Constructor");
	MutantStack<int> msCopy(ms);
	
	std::cout << "Copy Size: " << msCopy.size() << ", Copy Top: " << msCopy.top() << std::endl;
	
	
	
	/*  ======= Assignment Operator =======  */
	
	Title ("Assignment Operator");
	MutantStack<int> msAssign;
	msAssign = ms;
	
	std::cout << "Assign Size: " << msAssign.size() << ", Assign Top: " << msAssign.top() << std::endl;
	
	msAssign.push (999);
	
	std::cout << "Assign Size: " << msAssign.size() << ", Assign Top: " << msAssign.top() << std::endl;
	
	
	return 0;
	
}

