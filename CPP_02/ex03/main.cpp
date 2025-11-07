/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:28:27 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/07 13:12:45 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	std::cout << BOLD_C << "\n Test 1 - Basic triangle" << RST << std::endl;
	{
		Point a;
		Point b(2,4);
		Point c(4,0);
		
		Point p1(2,2);		// inside
		Point p2(2,4);		// vertex
		Point p3(c);		// vertex
		Point p4(0,2);		// inside
		Point p5(5,2);		// outside
		Point p6(2,-1);		// outside
		Point p7(0.9,1.8);	// near edge
		Point p8(3.102f,1.801f); // slightly outside

		std::cout << "p1(2,2)  inside? " << bsp(a, b, c, p1) << std::endl;
		std::cout << "p2(2,4)  inside? " << bsp(a, b, c, p2) << std::endl;
		std::cout << "p3(c)    inside? " << bsp(a, b, c, p3) << std::endl;
		std::cout << "p4(0,2)  inside? " << bsp(a, b, c, p4) << std::endl;
		std::cout << "p5(5,2)  inside? " << bsp(a, b, c, p5) << std::endl;
		std::cout << "p6(2,-1) inside? " << bsp(a, b, c, p6) << std::endl;
		std::cout << "p7(2,-1) inside? " << bsp(a, b, c, p7) << std::endl;
		std::cout << "p8(3.102f,1.801f) " << bsp(a, b, c, p8) << std::endl;
	}
	
	std::cout << BOLD_C << "\n Test 2 - Skewed triangle" << RST << std::endl;
	{
		Point a(-2,1);
		Point b(3,5);
		Point c(5,-1);

		Point p1(2,2);		// inside
		Point p2(c);		// vertex
		Point p3(0,0);		// outside
		Point p4(3,2.5);	// inside
		Point p5(4,0);		// inside
		Point p6(1,0);		//inside or outside barelly?

		std::cout << "p1(2,2)   inside? " << bsp(a, b, c, p1) << std::endl;
		std::cout << "p2(c)     inside? " << bsp(a, b, c, p2) << std::endl;
		std::cout << "p3(0,0)   inside? " << bsp(a, b, c, p3) << std::endl;
		std::cout << "p4(3,2.5) inside? " << bsp(a, b, c, p4) << std::endl;
		std::cout << "p5(4,0)   inside? " << bsp(a, b, c, p5) << std::endl;
		std::cout << "p6(1,0)   inside? " << bsp(a, b, c, p6) << std::endl;
	}
	std::cout << BOLD_C << "\n Test 3 - Badly constructed triangle " 
			  << RST << std::endl;
	{
		Point a(1,1);
		Point b(1,1);
		Point c(2,2);
		
		Point p(1.5,1.5);
		
		std::cout << "p(1.5,1.5) inside? " << bsp(a, b, c, p) << std::endl;
	}
	return 0;
}
