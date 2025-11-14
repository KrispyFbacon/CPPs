/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/14 17:17:47 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Unknown WrongAnimal")
{
	std::cout << CLASS_COLOR << "WrongAnimal "
			  << G << "Default Constructor called"
			  << RST << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type)
{
	std::cout << CLASS_COLOR << "WrongAnimal "
			  << G << "Copy Constructor called"
			  << RST << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << CLASS_COLOR << "WrongAnimal "
			  << R << "Destructor called"
			  << RST << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << CLASS_COLOR << "WrongAnimal "
			  << G << "Copy assignment operator called"
			  << RST << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void WrongAnimal::makeSound()
{
	std::cout << CLASS_COLOR << "WrongAnimal "
			  << RST << "an appropriate sound (cats don't bark)."
			  << std::endl;
}

const std::string& WrongAnimal::getType() const
{
	return this->_type;
}

void WrongAnimal::setType(const std::string& type)
{
	this->_type = type;
}