/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/27 17:18:25 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

int	Character::_characterCount = 0;
AMateria*	Character::_floor[MAX_FLOOR] = {NULL};

Character::Character() : _name("Default"), _inventory()
{
	std::cout << CLASS_COLOR << "Character "
			  << G << "Default Constructor called"
			  << RST << std::endl;
	_initInventory();
	_characterCount++;
}

Character::Character(std::string const& name) : _name(name), _inventory()
{
	std::cout << CLASS_COLOR << "Character "
			  << G << "Constructor called"
			  << RST << std::endl;
	_initInventory();
	_characterCount++;
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
	_characterCount--;
	_cleanFloor();
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
	if (!_isMateriaEquipable(m))
		return ;
	
	for (int i = 0; i < _inventorySize; ++i)
	{
		if (this->_inventory[i] == NULL)
		{
			_updateFlooredItem(m);
			this->_inventory[i] = m;
			m->setHolder(this);
			
			std::cout << "Equiped " << m->getColoredType() << RST
					  << " in " << NAME_COLOR << this->_name << RST
					  << "'s inventory number " << NUM_COLOR << i
					  << RST << std::endl;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if(!_isValidIdx(idx))
		return ;
	if (!this->_inventory[idx])
	{
		std::cout << "Cannot unequip "
				  << NAME_COLOR << this->_name
				  << RST << "'s inventory number "
				  << NUM_COLOR << idx
				  << RST << " because it's already empty!" << std::endl;
		return ;
	}
	
	if (_dropItem(this->_inventory[idx]))
	{
		std::cout << MATE_COLOR << "Materia "
				<< this->_inventory[idx]->getColoredType()
				<< RST << " was unequiped from "
				<< NAME_COLOR << this->_name
				<< RST << "'s inventory number "
				<< NUM_COLOR << idx
				<< RST << std::endl;

		this->_inventory[idx] = NULL;
		return ;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if(!_isValidIdx(idx))
		return ;
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

void Character::discard(int idx)
{
	if(!_isValidIdx(idx))
		return ;
	if (!this->_inventory[idx])
	{
		std::cout << " Cannot unequip "
				  << NAME_COLOR << this->_name
				  << RST << "'s inventory number "
				  << NUM_COLOR << idx
				  << RST << " because it's already empty!" << std::endl;
		return ;
	}
	
	std::cout << "Discarding " << this->_inventory[idx]->getColoredType() 
			  << " from " << NAME_COLOR << this->_name
			  << RST << "'s inventory number " 
			  << NUM_COLOR << idx << RST << std::endl;
	
	delete this->_inventory[idx];
	this->_inventory[idx] = NULL;
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


/* ---------------------- Private Inventory Fuctions ----------------------- */

void	Character::_initInventory()
{
	for (int i = 0; i < _inventorySize; ++i)
		this->_inventory[i] = NULL;
}

bool	Character::_isValidIdx(int idx)
{
	if (idx < 0 || idx >= _inventorySize)
	{
		std::cerr << "Index outside of "
				  << NAME_COLOR << this->_name << RST
				  << "'s scope!" << std::endl;
		return false;
	}
	return true;
}

bool	Character::_isMateriaEquipable(AMateria* m)
{
	if (!m)
	{
		printError("Nothing to equip!");
		return false;
	}
	else if (m->getHolder() == this)
	{
		printError("This materia is already equipped by this Character!");
		return false;
	}
	else if (m->getHolder() != NULL)
	{
		std::cerr << BOLD_R << "Error: "
				  << RST << "This materia is already equipped in "
				  << NAME_COLOR << m->getHolder()->getName()
				  << RST << " inventory" << std::endl;
		return false;
	}
	for (int i = 0; i < _inventorySize; ++i)
	{
		if (this->_inventory[i] == NULL)
			return true;
	}
	
	std::cout << NAME_COLOR << this->_name
			  << RST << "'s inventory is full cannot equip "
			  << m->getColoredType() << RST << std::endl;
	return false;
}


/* ------------------------ Private Floor Fuctions ------------------------- */

void	Character::_updateFlooredItem(AMateria* item)
{
	for (int i = 0; i < _maxFloorItem; ++i)
	{
		if (this->_floor[i] == item)
		{
			this->_floor[i] = NULL;
			return ;
		}
	}
}

bool	Character::_dropItem(AMateria* item)
{
	for (int i = 0; i < _maxFloorItem; ++i)
	{
		if (this->_floor[i] == NULL)
		{
			item->setHolder(NULL);
			this->_floor[i] = item;
			return true;
		}
	}
	printError("Cannot unequip item, because floor is full!");
	return false;
}

void	Character::_cleanFloor()
{
	if (_characterCount == 0)
	{
		for (int i = 0; i < _maxFloorItem; ++i)
		{
			delete this->_floor[i];
			_floor[i] = NULL;
		}
	}
}