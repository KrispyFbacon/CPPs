/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/18 17:26:17 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain())
{
	std::cout << CLASS_COLOR << "Dog "
			  << G << "Default Constructor called"
			  << RST << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*(other._brain)))
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
	delete _brain;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << CLASS_COLOR << "Dog "
			  << G << "Copy assignment operator called"
			  << RST << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*(this->_brain) = *(other._brain);
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << CLASS_COLOR << "Dog "
			  << RST << "Woof Woof!"
			  << std::endl;
}

Brain* Dog::getBrain() const
{
	return this->_brain;
}