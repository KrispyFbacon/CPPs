/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/27 12:58:34 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type(""), _holder(NULL)
{
	std::cout << CLASS_COLOR << "AMateria "
			  << G << "Default Constructor called"
			  << RST << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type), _holder(NULL)
{
	std::cout << CLASS_COLOR << "AMateria "
			  << G << "Constructor called"
			  << RST << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type), _holder(NULL)
{
	std::cout << CLASS_COLOR << "AMateria "
			  << G << "Copy Constructor called"
			  << RST << std::endl;
}

AMateria::~AMateria()
{
	std::cout << CLASS_COLOR << "AMateria "
			  << R << "Destructor called"
			  << RST << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	std::cout << CLASS_COLOR << "AMateria "
			  << G << "Copy assignment operator called"
			  << RST << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}


/* -------------------------------- Getters -------------------------------- */

const std::string& AMateria::getType() const
{
	return this->_type;
}

std::string AMateria::getColoredType() const
{
	if (this->_type == "ice")
		return ICE_COLOR + this->_type + RST;
		
	else if (this->_type == "cure")
		return HEAL_COLOR + this->_type + RST;

	return MATE_COLOR + this->_type + RST;
}

ICharacter* AMateria::getHolder() const
{
	return this->_holder;
}

/* -------------------------------- Setters -------------------------------- */

void AMateria::setHolder(ICharacter* src)
{
	this->_holder = src;
}


/* -------------------------------- Actions -------------------------------- */

AMateria* AMateria::clone() const
{
	std::cout << CLASS_COLOR << "AMateria "
			  << RST << "Cannot clone Mateira dummy"
			  << RST << std::endl;
	return (NULL);
}

void AMateria::use(ICharacter& target)
{
	std::cout << CLASS_COLOR << "AMateria "
				<< RST << "Tried to use "
				<< BOLD_BLACK << "VOID"
				<< RST << " on " << NAME_COLOR << target.getName()
				<< RST << " ... nothing happen"
				<< RST << std::endl;
}