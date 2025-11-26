/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/26 13:40:20 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _type("")
{
	std::cout << CLASS_COLOR << "MateriaSource "
			  << G << "Default Constructor called"
			  << RST << std::endl;
}

MateriaSource::MateriaSource(std::string const& type) : _type(type)
{
	std::cout << CLASS_COLOR << "MateriaSource "
			  << G << "Constructor called"
			  << RST << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) : _type(other._type)
{
	std::cout << CLASS_COLOR << "MateriaSource "
			  << G << "Copy Constructor called"
			  << RST << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << CLASS_COLOR << "MateriaSource "
			  << R << "Destructor called"
			  << RST << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << CLASS_COLOR << "MateriaSource "
			  << G << "Copy assignment operator called"
			  << RST << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void learnMateria(AMateria*);
AMateria* createMateria(std::string const & type);