/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/20 18:22:04 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << CLASS_COLOR << "Ice "
			  << G << "Constructor called"
			  << RST << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	std::cout << CLASS_COLOR << "Ice "
			  << G << "Copy Constructor called"
			  << RST << std::endl;
	this->_type = "ice";
}

Ice::~Ice()
{
	std::cout << CLASS_COLOR << "Ice "
			  << R << "Destructor called"
			  << RST << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	std::cout << CLASS_COLOR << "Ice "
			  << G << "Copy assignment operator called"
			  << RST << std::endl;
	if (this != &other)
	{
		AMateria::operator=(*this);
	}
	return (*this);
}

AMateria* Ice::clone() const
{
	AMateria* clone = new Ice(*this);

	return (clone);
}

void Ice::tempUse(const std::string& target) const
{
	std::cout << CLASS_COLOR << "Cure "
			  << NAME_COLOR << this->_type
			  << ICE_COLOR << " ❄️  shoots an ice bolt at "
			  << NAME_COLOR << target << " ❄️"
			  << RST << std::endl;
}