/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/18 11:35:07 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << CLASS_COLOR << "Cat "
			  << G << "Default Constructor called"
			  << RST << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << CLASS_COLOR << "Cat "
			  << G << "Copy Constructor called"
			  << RST << std::endl;
}

Cat::~Cat()
{
	std::cout << CLASS_COLOR << "Cat "
			  << R << "Destructor called"
			  << RST << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << CLASS_COLOR << "Cat "
			  << G << "Copy assignment operator called"
			  << RST << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << CLASS_COLOR << "Cat "
			  << RST << "Meow Meow!"
			  << std::endl;
}