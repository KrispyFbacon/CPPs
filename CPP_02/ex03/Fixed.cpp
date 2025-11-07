/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/07 12:01:39 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ----------------------- Constructors / Destructor ----------------------- */

const int Fixed::_bits = 8;

Fixed::Fixed() : _value(0)
{
	if (DEBUG) std::cout << G << "Fixed Default constructor called" << RST << std::endl;
}

Fixed::Fixed(const int num)
{
	if (DEBUG) std::cout << G << "Fixed Int constructor called" << RST << std::endl;
	this->_value = num << _bits;
}

Fixed::Fixed(const float num)
{
	if (DEBUG) std::cout << G << "Fixed Float constructor called" << RST << std::endl;
	this->_value = roundf(num * (1 << _bits));
}

Fixed::Fixed(const Fixed& other)
{
	if (DEBUG) std::cout << Y << "Fixed Copy constructor called" << RST << std::endl;
	*this = other; //calls assigment operator
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (DEBUG) std::cout << Y << "Fixed Copy assignment operator called" << RST << std::endl;
	if (this != &other)
	{
		this->_value = other._value;
	}
	return (*this);
}

Fixed::~Fixed()
{
	if (DEBUG) std::cout << R << "Fixed Destructor called" << RST << std::endl;
}

/* ------------------------- Comparisons Operators ------------------------- */

bool Fixed::operator>(const Fixed& other) const
{
	return this->_value > other._value;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->_value != other._value;
}

/* -------------------------- Arithmetic Operators ------------------------- */

Fixed Fixed::operator+(const Fixed& other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

/* --------------------- Increment/Decrement Operators --------------------- */


Fixed& Fixed::operator++()
{
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_value++;
	return (temp);
}

Fixed& Fixed:: operator--()
{
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_value--;
	return (temp);
}

/* ---------------------  Compound Assignment Operator --------------------- */


Fixed& Fixed::operator+=(const Fixed& other)
{
	this->_value += other._value;
	return *this;
}

Fixed& Fixed::operator-=(const Fixed& other)
{
	this->_value -= other._value;
	return *this;
}

Fixed& Fixed::operator*=(const Fixed& other)
{
	this->_value = roundf((this->toFloat() * other.toFloat()) * (1 << _bits));
	return *this;
}

Fixed& Fixed::operator/=(const Fixed& other)
{
	this->_value = roundf((this->toFloat() / other.toFloat()) * (1 << _bits));
	return *this;
}

/* ----------------------------- Return min/max ---------------------------- */

Fixed Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

/* ------------------------------- Conversion ------------------------------ */

float Fixed::toFloat( void ) const
{
	return static_cast<float>(this->_value) / (1 << _bits);
}

int Fixed::toInt( void ) const
{
	return this->_value >> _bits;
}

/* --------------------------- Setters / Getters --------------------------- */

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

/* ---------------------------- Stream Operator ---------------------------- */

std::ostream& operator<<(std::ostream& os, const Fixed& fixedPoint)
{
	os << fixedPoint.toFloat();
	return (os);
}
