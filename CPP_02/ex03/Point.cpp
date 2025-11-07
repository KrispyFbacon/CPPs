/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:38:32 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/07 14:53:38 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	if (DEBUG)
		std::cout << G << "Point Default constructor called" << RST << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	if (DEBUG)
		std::cout << G << "Point Default constructor called" << RST << std::endl;
}

Point::Point(const Point& other) : _x(other._x), _y(other._y)
{
	if (DEBUG)
		std::cout << Y << "Point Copy constructor called" << RST << std::endl;
}

Point& Point::operator=(const Point& other)
{
	if (DEBUG)
		std::cout << Y << "Point Copy assignment operator called" << RST << std::endl;
		
	if (this != &other) {}
	
	return(*this);
}

Point::~Point()
{
	if (DEBUG)
		std::cout << R << "Point Destructor called" << RST << std::endl;
}

const Fixed& Point::getX() const
{
	return this->_x;
}

const Fixed& Point::getY() const
{
	return this->_y;
}
