/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/14 17:09:22 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Unknown Animal")
{
	std::cout << CLASS_COLOR << "Animal "
			  << G << "Default Constructor called"
			  << RST << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
	std::cout << CLASS_COLOR << "Animal "
			  << G << "Copy Constructor called"
			  << RST << std::endl;
}

Animal::~Animal()
{
	std::cout << CLASS_COLOR << "Animal "
			  << R << "Destructor called"
			  << RST << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << CLASS_COLOR << "Animal "
			  << G << "Copy assignment operator called"
			  << RST << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void Animal::makeSound()
{
	std::cout << CLASS_COLOR << "Animal "
			  << RST << "an appropriate sound (cats don't bark)."
			  << std::endl;
}

const std::string& Animal::getType() const
{
	return this->_type;
}

void Animal::setType(const std::string& type)
{
	this->_type = type;
}