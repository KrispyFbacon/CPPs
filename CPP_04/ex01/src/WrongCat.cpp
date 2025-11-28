/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/18 11:35:28 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << CLASS_COLOR << "WrongCat "
			  << G << "Default Constructor called"
			  << RST << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << CLASS_COLOR << "WrongCat "
			  << G << "Copy Constructor called"
			  << RST << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << CLASS_COLOR << "WrongCat "
			  << R << "Destructor called"
			  << RST << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << CLASS_COLOR << "WrongCat "
			  << G << "Copy assignment operator called"
			  << RST << std::endl;
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << CLASS_COLOR << "WrongCat "
			  << RST << "Meow Meow!"
			  << std::endl;
}