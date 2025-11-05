/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/05 18:18:38 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;


// Orthodox Canonical Form
Fixed::Fixed() : _value(0)
{
	std::cout << G << "Default constructor called" << RST << std::endl;
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


// Extra Constructors
Fixed::Fixed(const int num)
{
	std::cout << G << "Int constructor called" << RST << std::endl;
	this->_value = num << _bits;
}

Fixed::Fixed(const float num)
{
	std::cout << G << "Float constructor called" << RST << std::endl;
	this->_value = num * (1 << _bits);
}


float Fixed::toFloat( void ) const
{
	return (float)this->_value / (1 << _bits);
}

int Fixed::toInt( void ) const
{
	return this->_value >> _bits;
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
	os << fixedPoint.toFloat();
	return (os);
}
