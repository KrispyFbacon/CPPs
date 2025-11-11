/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:28:27 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/11 11:06:22 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	
	c = b;

	std::cout << "A: "<< a.getRawBits() << std::endl;
	std::cout << "B: "<< b.getRawBits() << std::endl;
	std::cout << "C: "<< c.getRawBits() << std::endl;

	b.setRawBits(4);
	std::cout << "B: "<< b.getRawBits() << std::endl;	

	return (0);
}
