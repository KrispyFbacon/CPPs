/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/05 15:41:27 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed() : _value(0)
{
	std::cout << G << "Default constructor called" << RST << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << G << "Int constructor called" << RST << std::endl;
	this->_value = num;
}

Fixed::Fixed(const float num)
{
	std::cout << G << "Long constructor called" << RST << std::endl;
	(float)this->_value = num;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << Y << "Copy constructor called" << RST << std::endl;
	*this = other; //calls assigment operator
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << Y << "Copy assignment operator called" << RST << std::endl;
	if (this != &other)
	{
		this->_value = other._value;
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << R << "Destructor called" << RST << std::endl;
}


float Fixed::toFloat( void ) const
{
	
}

int Fixed::toInt( void ) const
{
	
}


void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}



std::ostream& operator<<(std::ostream& os, const Fixed& fixedPoint)
{
	os << fixedPoint.getRawBits();
	return (os);
}
