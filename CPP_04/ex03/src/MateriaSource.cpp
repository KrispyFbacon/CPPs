/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/27 12:51:30 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _materias()
{
	std::cout << CLASS_COLOR << "MateriaSource "
			  << G << "Default Constructor called"
			  << RST << std::endl;
	for (int i = 0; i < _materiaSize; ++i)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) : _materias()
{
	std::cout << CLASS_COLOR << "MateriaSource "
			  << G << "Copy Constructor called"
			  << RST << std::endl;
	for (int i = 0; i < _materiaSize; ++i)
	{
		if (other._materias[i])
			this->_materias[i] = other._materias[i]->clone();
		else
			this->_materias[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	std::cout << CLASS_COLOR << "MateriaSource "
			  << R << "Destructor called"
			  << RST << std::endl;
	for (int i = 0; i < _materiaSize; ++i)
	{
		if (this->_materias[i])
		{
			delete this->_materias[i];
			this->_materias[i] = NULL;
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{ 
	std::cout << CLASS_COLOR << "MateriaSource "
			  << G << "Copy assignment operator called"
			  << RST << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < _materiaSize; ++i)
		{
			delete this->_materias[i];
			if (other._materias[i])
				this->_materias[i] = other._materias[i]->clone();
			else
				this->_materias[i] = NULL;
		}
	}
	return (*this);
}


void MateriaSource::learnMateria(AMateria* src)
{
	if (!src)
	{
		printError("Nothing to learn!");
		return ;
	}
	for (int i = 0; i < _materiaSize; ++i)
	{
		if (!this->_materias[i])
		{
			this->_materias[i] = src;
			std::cout << CLASS_COLOR << "MaterialSource"
					  << RST << " learned " << src->getColoredType()
					  << RST << " into slot number "
					  << NUM_COLOR << i << RST << std::endl;
			return ;
		}
	}
	std::cout << CLASS_COLOR << "MaterialSource"
			  << RST << " has no slots to learn "
			  << src->getColoredType() << RST << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; (i < _materiaSize && _materias[i]); ++i)
	{
		if (this->_materias[i] && this->_materias[i]->getType() == type)
		{
			std::cout << CLASS_COLOR << "MateriaSource"
					  << RST << " created " << this->_materias[i]->getColoredType()
					  << RST << " into slot number "
					  << NUM_COLOR << i << RST << std::endl;
			return this->_materias[i]->clone();
		}
	}
	std::cout << CLASS_COLOR << "MateriaSource"
			  << RST << " could not create "
			  << MATE_COLOR << "Materia " << printType(type)
			  << RST << ", because it hasn't learned yet!" << std::endl;
	return (NULL);
}