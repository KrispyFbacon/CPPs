/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:05:40 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/19 17:20:46 by frbranda         ###   ########.fr       */
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

template <typename T>
void runTest(const T& a, const T& b)
{
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << std::endl;
}

int main( void )
{
	// Int
	int a = 2;
	int b = 3;
	::runTest(a, b);


	// String
	std::string c = "chaine1";
	std::string d = "chaine2";
	::runTest(c, d);


	// Double
	double e = 4.2;
	double f = 5.8;
	::runTest(e, f);


	// const int
	const int g = 1;
	const int h = 6;
	::runTest(g, h);
	
	return 0;
}

