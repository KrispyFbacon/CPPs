/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:28:27 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/07 17:33:53 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	std::cout << BOLD_Y << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_Y << "║  Test 0 - Test getX and getY           ║" << RST << std::endl;
	std::cout << BOLD_Y << "╚════════════════════════════════════════╝" << RST << std::endl;
	{
		Point a;
		Point b(3.5f, 2.0f);
		Point c(b);
		
		a = b;
		
		std::cout << "a: (" << a.getX() << ", " << a.getY() << ")" << std::endl;
		std::cout << "b: (" << b.getX() << ", " << b.getY() << ")" << std::endl;
		std::cout << "c: (" << c.getX() << ", " << c.getY() << ")" << std::endl;
	}
	
	std::cout << BOLD_Y << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_Y << "║  Test 1 - Basic triangle               ║" << RST << std::endl;
	std::cout << BOLD_Y << "║  Triangle: A(0,0) B(2,4) C(4,0)        ║" << RST << std::endl;
	std::cout << BOLD_Y << "╚════════════════════════════════════════╝" << RST << std::endl;
	{
		Point a;
		Point b(2, 4);
		Point c(4, 0);
		
		Point p1(2, 2);
		Point p2(2, 4);
		Point p3(c);
		Point p4(0, 2);
		Point p5(5, 2);
		Point p6(2, -1);
		Point p7(0.9033f, 1.8f);
		Point p8(3.102f, 1.801f);
		
		std::cout << BOLD_C "p1(2,2):           " << (bsp(a, b, c, p1) ? (G "inside") : (R "outside")) << RST << std::endl;
		std::cout << BOLD_C "p2(2,4):           " << (bsp(a, b, c, p2) ? (G "inside") : (R "outside")) << RST << std::endl;
		std::cout << BOLD_C "p3(4,0):           " << (bsp(a, b, c, p3) ? (G "inside") : (R "outside")) << RST << std::endl;
		std::cout << BOLD_C "p4(0,2):           " << (bsp(a, b, c, p4) ? (G "inside") : (R "outside")) << RST << std::endl;
		std::cout << BOLD_C "p5(5,2):           " << (bsp(a, b, c, p5) ? (G "inside") : (R "outside")) << RST << std::endl;
		std::cout << BOLD_C "p6(2,-1):          " << (bsp(a, b, c, p6) ? (G "inside") : (R "outside")) << RST << std::endl;
		std::cout << BOLD_C "p7(0.9033, 1.8):   " << (bsp(a, b, c, p7) ? (G "inside") : (R "outside")) << RST << std::endl;
		std::cout << BOLD_C "p8(3.102,1.801):   " << (bsp(a, b, c, p8) ? (G "inside") : (R "outside")) << RST << std::endl;
	}
	
	std::cout << BOLD_Y << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_Y << "║  Test 2 - Skewed triangle              ║" << RST << std::endl;
	std::cout << BOLD_Y << "║  Triangle: A(-2,1) B(3,5) C(5,-1)      ║" << RST << std::endl;
	std::cout << BOLD_Y << "╚════════════════════════════════════════╝" << RST << std::endl;
	{
		Point a(-2, 1);
		Point b(3, 5);
		Point c(5, -1);
		
		Point p1(2, 2);
		Point p2(c);
		Point p3(0, 0);
		Point p4(3, 2.5);
		Point p5(4, 0);
		Point p6(1, 0);
		
		std::cout << BOLD_C "p1(2,2):           " << (bsp(a, b, c, p1) ? (G "inside") : (R "outside")) << RST << std::endl;
		std::cout << BOLD_C "p2(5,-1):          " << (bsp(a, b, c, p2) ? (G "inside") : (R "outside")) << RST << std::endl;
		std::cout << BOLD_C "p3(0,0):           " << (bsp(a, b, c, p3) ? (G "inside") : (R "outside")) << RST << std::endl;
		std::cout << BOLD_C "p4(3,2.5):         " << (bsp(a, b, c, p4) ? (G "inside") : (R "outside")) << RST << std::endl;
		std::cout << BOLD_C "p5(4,0):           " << (bsp(a, b, c, p5) ? (G "inside") : (R "outside")) << RST << std::endl;
		std::cout << BOLD_C "p6(1,0):           " << (bsp(a, b, c, p6) ? (G "inside") : (R "outside")) << RST << std::endl;
	}
	
	std::cout << BOLD_Y << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_Y << "║  Test 3 - Degenerate triangle          ║" << RST << std::endl;
	std::cout << BOLD_Y << "║  Triangle: A(1,1) B(1,1) C(2,2)        ║" << RST << std::endl;
	std::cout << BOLD_Y << "║  (Collinear points - not a triangle)   ║" << RST << std::endl;
	std::cout << BOLD_Y << "╚════════════════════════════════════════╝" << RST << std::endl;
	{
		Point a(1, 1);
		Point b(1, 1);
		Point c(2, 2);
		
		Point p(1.5f, 1.5f);
		
		std::cout << "p(1.5,1.5):        " << (bsp(a, b, c, p) ? (G "inside") : (R "outside")) << RST << std::endl;
	}
	
	return 0;
}
