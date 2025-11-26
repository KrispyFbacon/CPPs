/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/26 17:13:15 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Default"), _inventory()
{
	std::cout << CLASS_COLOR << "Character "
			  << G << "Default Constructor called"
			  << RST << std::endl;
	_initInventory();
}

Character::Character(std::string const& name) : _name(name), _inventory()
{
	std::cout << CLASS_COLOR << "Character "
			  << G << "Constructor called"
			  << RST << std::endl;
	_initInventory();
}

Character::Character(const Character& other) : _name(other._name), _inventory()
{
	std::cout << CLASS_COLOR << "Character "
			  << G << "Copy Constructor called"
			  << RST << std::endl;
	for (int i = 0; i < _inventorySize; ++i)
	{
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

Character::~Character()
{
	std::cout << CLASS_COLOR << "Character "
			  << R << "Destructor called"
			  << RST << std::endl;
	for (int i = 0; i < _inventorySize; ++i)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
}

Character& Character::operator=(const Character& other)
{
	std::cout << CLASS_COLOR << "Character "
			  << G << "Copy assignment operator called"
			  << RST << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < _inventorySize; ++i)
		{
			delete this->_inventory[i];
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}


std::string const & Character::getName() const
{
	return this->_name;
}

/* ------------------------------- Inventory ------------------------------- */

void Character::equip(AMateria* m)
{
	if (!m)
	{
		printError("Nothing to equip!");
		return ;
	}
	for (int i = 0; i < _inventorySize; ++i)
	{
		if (!this->_inventory[i])
		{
			//TODO  check if i equip the same Materia more than once
			this->_inventory[i] = m;
			std::cout << "Equiped " << m->getColoredType() 
					  << RST << " in "
					  << NAME_COLOR << this->_name 
					  << RST << "'s inventory number "
					  << NUM_COLOR << i << RST << std::endl;
			return ;
		}
	}
	std::cout << NAME_COLOR << this->_name
			  << RST << "'s inventory is full cannot equip "
			  << m->getColoredType() << RST << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= _inventorySize)
	{
		std::cout << "Index outside of "
				  << NAME_COLOR << this->_name
				  << "'s scope!" << std::endl;
		return ;
	}
	if (!this->_inventory[idx])
	{
		std::cout << " Cannot unequip "
				  << NAME_COLOR << this->_name
				  << RST << "'s inventory number "
				  << NUM_COLOR << idx
				  << RST << " because it's already empty!" << std::endl;
	}
	else
	{
		std::cout << " Materia " << this->_inventory[idx]->getColoredType()
				  << RST << " was unequiped from "
				  << NAME_COLOR << this->_name
				  << RST << "'s inventory number "
				  << NUM_COLOR << idx
				  << RST << std::endl;
		this->_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= _inventorySize)
	{
		printError("Index outside of scope!");
		return ;
	}
	if (!this->_inventory[idx])
	{
		std::cout << NAME_COLOR << this->_name
				  << RST << " has no "
				  << MATE_COLOR << "Materia"
				  << RST " equiped on inventory space "
				  << NUM_COLOR << idx << RST << " so it cannot be used!" << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}

void Character::checkInventory()
{
	std::cout << "\n┌─────────────────────────────────────────┐\n";
	std::cout << "│ " << NAME_COLOR << this->_name
			  << RST << BOLD_M << " Inventory " << RST << std::endl;
	std::cout << "├──────┬──────────────────────────────────┤\n";
	std::cout << "│ " << BOLD_M << "Slot" << RST " │ " 
			  << BOLD_M << "Item " << RST << std::endl;
	std::cout << "├──────┼──────────────────────────────────┤" << RST << std::endl;
	for (int i = 0; i < _inventorySize; ++i)
	{
		if(!this->_inventory[i])
		{
			std::cout << "│ " 
				  << NUM_COLOR << std::setw(4) << std::left << i
				  << RST << " │ " << std::endl;
			continue ;
		}
		std::cout << "│ " 
				  << NUM_COLOR << std::setw(4) << std::left << i
				  << RST << " │ " << this->_inventory[i]->getColoredType()
				  << RST << std::endl;
	}
	std::cout << "└──────┴──────────────────────────────────┘\n" << std::endl;
}

void	Character::_initInventory()
{
	for (int i = 0; i < _inventorySize; ++i)
		this->_inventory[i] = NULL;
}