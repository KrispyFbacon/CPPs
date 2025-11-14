/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/14 17:12:55 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << CLASS_COLOR << "Dog "
			  << G << "Default Constructor called"
			  << RST << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << CLASS_COLOR << "Dog "
			  << G << "Copy Constructor called"
			  << RST << std::endl;
}

Dog::~Dog()
{
	std::cout << CLASS_COLOR << "Dog "
			  << R << "Destructor called"
			  << RST << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << CLASS_COLOR << "Dog "
			  << G << "Copy assignment operator called"
			  << RST << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
}

void Dog::makeSound()
{
	std::cout << CLASS_COLOR << "Dog "
			  << RST << "says: Woof Woof!"
			  << std::endl;
}