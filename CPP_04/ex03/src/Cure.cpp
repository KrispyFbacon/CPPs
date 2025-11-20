/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/20 18:22:02 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << CLASS_COLOR << "Cure "
			  << G << "Constructor called"
			  << RST << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	std::cout << CLASS_COLOR << "Cure "
			  << G << "Copy Constructor called"
			  << RST << std::endl;
	this->_type = "cure";
}

Cure::~Cure()
{
	std::cout << CLASS_COLOR << "Cure "
			  << R << "Destructor called"
			  << RST << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	std::cout << CLASS_COLOR << "Cure "
			  << G << "Copy assignment operator called"
			  << RST << std::endl;
	if (this != &other)
	{
		AMateria::operator=(*this);
	}
	return (*this);
}

AMateria* Cure::clone() const
{
	AMateria* clone = new Cure(*this);

	return (clone);
}

void Cure::tempUse(const std::string& target) const
{
	std::cout << CLASS_COLOR << "Cure "
			  << NAME_COLOR << this->_type
			  << HEAL_COLOR << " ✨ heals "
			  << NAME_COLOR << target
			  << HEAL_COLOR  << " wounds! ✨"
			  << RST << std::endl;
}