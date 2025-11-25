/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/25 12:06:24 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Default"), _inventory()
{
	std::cout << CLASS_COLOR << "Character "
			  << G << "Default Constructor called"
			  << RST << std::endl;
}

Character::Character(std::string const& name) : _name(name), _inventory()
{
	std::cout << CLASS_COLOR << "Character "
			  << G << "Constructor called"
			  << RST << std::endl;
}

Character::Character(const Character& other) : _name(other._name), _inventory()
{
	std::cout << CLASS_COLOR << "Character "
			  << G << "Copy Constructor called"
			  << RST << std::endl;
}

Character::~Character()
{
	std::cout << CLASS_COLOR << "Character "
			  << R << "Destructor called"
			  << RST << std::endl;
}

Character& Character::operator=(const Character& other)
{
	std::cout << CLASS_COLOR << "Character "
			  << G << "Copy assignment operator called"
			  << RST << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
	}
	return (*this);
}


std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	if (!m || m->getType().empty())
	{
		std::cout << "Nothing to equip!" << std::endl;
		return ;
	}
	for (int i = 0; i < MAX_INVENTORY; ++i)
	{
		if (this->_inventory[i]->getType().empty())
		{
			this->_inventory[i] = m;
			std::cout << "Equiped an Matria!" << std::endl;
			return ;
		}
	}
	std::cout << "Inventory full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= MAX_INVENTORY)
	{
		std::cout << BOLD_R << "Index outside of scope!" << RST << std::endl;
		return ;
	}
	if (this->_inventory[idx]->getType().empty())
		std::cout << "Nothing to unequip!" << std::endl;
	else
		std::cout << "Unequiped an Materia!" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= MAX_INVENTORY)
	{
		std::cout << BOLD_R << "Index outside of scope!" << RST << std::endl;
		return ;
	}
	if (this->_inventory[idx]->getType().empty())
	{
		std::cout << "No Materia equiped on that inventory space!" << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}

void Character::checkInventory()
{
	for (int i = 0; i < MAX_INVENTORY; ++i)
	{
		if (this->_inventory[i]->getType().empty())
		{
			std::cout << "Inventory[" << NUM_COLOR << i
				  << RST << "]: " << std::endl;
			continue ;
		}
		std::cout << "Inventory[" << NUM_COLOR << i << RST << "]: "
				  << NAME_COLOR << this->_inventory[i]->getType()
				  << RST << std::endl;
	}
}