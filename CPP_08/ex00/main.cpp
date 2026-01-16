/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:05:40 by frbranda          #+#    #+#             */
/*   Updated: 2026/01/16 13:24:50 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

# define BOLD_C		"\033[1;36m"
# define BOLD_Y		"\033[1;33m"
# define RST		"\033[0m"

void print_separator(std::string title)
{
	 std::cout << BOLD_C << "\n========== " << title << " ==========\n" << RST;
}


void test1_vector()
{
	print_separator("TEST 1: std::vector<int>");
	
	std::vector<int> vec;
	for (int i = 0; i < 10; ++i)
		vec.push_back(i * 10);
	
	std::cout << "Vector contents: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << "\n" << std::endl;
	
	// Test: Found
	try
	{
		std::cout << BOLD_Y << "Searching for 50... " << RST;
		std::vector<int>::iterator it = easyfind(vec, 50);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	// Test: Not found
	try
	{
		std::cout << BOLD_Y << "Searching for 999... " << RST;
		std::vector<int>::iterator it = easyfind(vec, 999);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	// Test: First element
	try
	{
		std::cout << BOLD_Y << "Searching for 0... " << RST;
		std::vector<int>::iterator it = easyfind(vec, 0);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	// Test: Last element
	try
	{
		std::cout << BOLD_Y << "Searching for 90... " << RST;
		std::vector<int>::iterator it = easyfind(vec, 90);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void test2_list()
{
	print_separator("TEST 2: std::list<int>");
	
	std::list<int> lst;
	for (int i = 1; i <= 5; ++i)
		lst.push_back(i * 100);
	
	std::cout << "List contents: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n" << std::endl;
	
	// Test: Found
	try
	{
		std::cout << BOLD_Y << "Searching for 300... " << RST;
		std::list<int>::iterator it = easyfind(lst, 300);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	// Test: Not found
	try
	{
		std::cout << BOLD_Y << "Searching for 42... " << RST;
		std::list<int>::iterator it = easyfind(lst, 42);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void test3_deque()
{
	print_separator("TEST 3: std::deque<int>");
	
	std::deque<int> deq;
	deq.push_back(7);
	deq.push_back(14);
	deq.push_back(21);
	deq.push_back(28);
	
	std::cout << "Deque contents: ";
	for (size_t i = 0; i < deq.size(); ++i)
		std::cout << deq[i] << " ";
	std::cout << "\n" << std::endl;
	
	// Test: Found
	try
	{
		std::cout << BOLD_Y << "Searching for 21... " << RST;
		std::deque<int>::iterator it = easyfind(deq, 21);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	// Test: Not found
	try
	{
		std::cout << BOLD_Y << "Searching for 35... " << RST;
		std::deque<int>::iterator it = easyfind(deq, 35);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void test4_set()
{
	print_separator("TEST 4: std::set<int>");
	
	std::set<int> s;
	s.insert(5);
	s.insert(15);
	s.insert(25);
	s.insert(35);
	s.insert(45);
	
	std::cout << "Set contents: ";
	for (std::set<int>::iterator it = s.begin(); it != s.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n" << std::endl;
	
	// Test: Found
	try
	{
		std::cout << BOLD_Y << "Searching for 25... " << RST;
		std::set<int>::iterator it = easyfind(s, 25);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	// Test: Not found
	try
	{
		std::cout << BOLD_Y << "Searching for 100... " << RST;
		std::set<int>::iterator it = easyfind(s, 100);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void test5_empty()
{
	print_separator("TEST 5: Empty vector");
	
	std::vector<int> empty_vec;
	std::cout << "Vector is empty\n" << std::endl;
	
	try
	{
		std::cout << BOLD_Y << "Searching for 42 in empty vector... " << RST;
		std::vector<int>::iterator it = easyfind(empty_vec, 42);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void test6_const()
{
	print_separator("TEST 6: Const containers");
	
	const std::vector<int> vec;

	try
	{
		std::cout << BOLD_Y << "Searching for 0 in empty container... " << RST;
		std::vector<int>::const_iterator it = easyfind(vec, 0);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	const std::vector<int> vec2(1);

	try
	{
		std::cout << BOLD_Y << "Searching for 0 in single-element container... " << RST;
		std::vector<int>::const_iterator it = easyfind(vec2, 0);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
}

int main(void)
{
	test1_vector();
	test2_list();
	test3_deque();
	test4_set();
	test5_empty();
	test6_const();
	
	return 0;
}

