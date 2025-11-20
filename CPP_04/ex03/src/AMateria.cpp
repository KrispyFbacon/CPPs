/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/20 18:26:45 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const& type) : _type(type)
{
	std::cout << CLASS_COLOR << "AMateria "
			  << G << "Default Constructor called"
			  << RST << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
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

const std::string& AMateria::getType() const
{
	return this->_type;
}

AMateria* AMateria::clone() const
{
	std::cout << CLASS_COLOR << "AMateria "
			  << RST << "Cannot clone Mateira dummy"
			  << RST << std::endl;
	return (NULL);
}

void AMateria::tempUse(const std::string& target) const
{
	std::cout << CLASS_COLOR << "AMateria "
			  << NAME_COLOR << this->_type
			  << RST << " used "
			  << BOLD_BLACK << "VOID "
			  << NAME_COLOR << target
			  << RST << " ... nothing happen"
			  << RST << std::endl;
}

// void AMateria::use(ICharacter& target)
// {
// 	std::cout << CLASS_COLOR << "AMateria "
// 			  << RST << "Tried to use "
// 			  << BOLD_BLACK << "VOID"
// 			  << RST << " ... nothing happen"
// 			  << RST << std::endl;
// }