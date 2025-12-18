/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:05:40 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/18 18:37:59 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

void test1_Int()
{

}

void test2_Double()
{

}

void test3_String()
{

}

int main ()
{
	int	a = 4;
	int b = 2;


	std::cout << "=== Before Swap ===" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	
	Whatever<int>::swap(a, b);

	std::cout << "\n=== After Swap ===" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	
	
	std::cout << "\nmin( a, b ) = " << Whatever<int>::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << Whatever<int>::max( a, b ) << std::endl;

	
}

