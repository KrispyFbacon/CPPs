/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:28:27 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/06 16:52:48 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{

	std::cout << BOLD_C << "---- Basic test from subject ----"
				  << RST << std::endl;
	{
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));
		
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		
		std::cout << b << std::endl;
		
		std::cout << Fixed::max(a, b) << std::endl;
	}


	std::cout << BOLD_C << "\n---- Comparisons ----" << RST << std::endl;
	{
		Fixed m(10.0f);
		Fixed n(20.0f);
		std::cout << "m = " << m << ", n = " << n << std::endl;
		std::cout << std::endl;
		
		std::cout << "m < n:   " << (m < n)  << std::endl;
		std::cout << "m > n:   " << (m > n)  << std::endl;
		std::cout << "m <= n:  " << (m <= n) << std::endl;
		std::cout << "m >= n:  " << (m >= n) << std::endl;
		std::cout << "m == n:  " << (m == n) << std::endl;
		std::cout << "m != n:  " << (m != n) << std::endl;
	}


	std::cout << BOLD_C << "\n---- Arithmetic operators ----"
			  << RST << std::endl;
	{
		Fixed x(3.5f);
		Fixed y(1.25f);
		std::cout << "x = " << x << ", y = " << y << std::endl;
		std::cout << std::endl;

		std::cout << "x + y = " << (x + y) << std::endl;
		std::cout << "x - y = " << (x - y) << std::endl;
		std::cout << "x * y = " << (x * y) << std::endl;
		std::cout << "x / y = " << (x / y) << std::endl;
	}

	std::cout << BOLD_C << "\n---- Increment / Decrement ----"
			  << RST << std::endl;
	{
		Fixed e;
		std::cout << e << std::endl;
		std::cout << ++e << std::endl;
		std::cout << e++ << std::endl;
		std::cout << e << std::endl;
		std::cout << --e << std::endl;
		std::cout << e-- << std::endl;
		std::cout << e << std::endl;
	}


	std::cout << BOLD_C << "\n---- Compound assignment ----"
			  << RST << std::endl;
	{
		Fixed c(2.0f);
		Fixed d(3.0f);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << std::endl;
		
		c += d;
		std::cout << "| c += d | -> " << c << std::endl;
		
		c -= Fixed(1.0f);
		std::cout << "| c -= 1 | -> " << c << std::endl;
		
		c *= Fixed(2.0f);
		std::cout << "| c *= 2 | -> " << c << std::endl;
		
		c /= Fixed(4.0f);
		std::cout << "| c /= 4 | -> " << c << std::endl;
	}


	std::cout << BOLD_C << "\n---- Min / Max ----" << RST << std::endl;
	{
		Fixed f(42.42f);
		Fixed g(42.43f);
		std::cout << "f = " << f << ", g = " << g << std::endl;
		std::cout << std::endl;
		
		std::cout << "min(f, g) = " << Fixed::min(f, g) << std::endl;
		std::cout << "max(f, g) = " << Fixed::max(f, g) << std::endl;
	}


	std::cout << BOLD_C << "\n---- Const min/max ----" << RST << std::endl;
	{
		const Fixed cf(3.3f);
		const Fixed cg(3.3f);
		std::cout << "cf = " << cf << ", cg = " << cg << std::endl;
		std::cout << std::endl;
		
		std::cout << "min(cf, cg) = " << Fixed::min(cf, cg) << std::endl;
		std::cout << "max(cf, cg) = " << Fixed::max(cf, cg) << std::endl;
	}

	return 0;
}
