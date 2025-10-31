/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/31 16:15:30 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << G << "Default Constructor called" << RST << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << G << "Copy Constructor called" << RST << std::endl;
	this = other;
}

Fixed::~Fixed()
{
	std::cout << G << "Destructor called" << RST << std::endl;
}


