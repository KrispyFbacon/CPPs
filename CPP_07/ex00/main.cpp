/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:05:40 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/19 15:45:11 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

template <typename T>
void runTest(T& a, T& b)
{
	::swap( a, b );
	
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << std::endl;
}

int main( void )
{
	int a = 2;
	int b = 3;
	
	::runTest(a, b);
	

	std::string c = "chaine1";
	std::string d = "chaine2";
	
	::runTest(c, d);

	
	double e = 4.2;
	double f = 5.8;
	
	::runTest(e, f);


	const int g = 1;
	const int h = 6;
	
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << std::endl;
	
	return 0;
}



// void test1_Int()
// {

// }

// void test2_Double()
// {

// }

// void test3_String()
// {

// }

// int main ()
// {
// 	int	a = 4;
// 	int b = 2;


// 	std::cout << "=== Before Swap ===" << std::endl;
// 	std::cout << "a: " << a << std::endl;
// 	std::cout << "b: " << b << std::endl;
	
// 	Whatever<int>::swap(a, b);

// 	std::cout << "\n=== After Swap ===" << std::endl;
// 	std::cout << "a: " << a << std::endl;
// 	std::cout << "b: " << b << std::endl;
	
	
// 	std::cout << "\nmin( a, b ) = " << Whatever<int>::min( a, b ) << std::endl;
// 	std::cout << "max( a, b ) = " << Whatever<int>::max( a, b ) << std::endl;

	
// }

