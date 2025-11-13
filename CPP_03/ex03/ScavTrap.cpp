/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/12 18:03:35 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default ScavTrap")
{
	_initScavStats();
	std::cout << CLASS_COLOR << "ScavTrap "
			  << G << "Default Constructor called"
			  << RST << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_initScavStats();
	std::cout << CLASS_COLOR << "ScavTrap "
			  << NAME_COLOR << this->_name
			  << G << " Constructor called"
			  << RST << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	this->_guardMode = other._guardMode;
	std::cout << CLASS_COLOR << "ScavTrap "
			  << NAME_COLOR << this->_name
			  << G << " Copy Constructor called"
			  << RST << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << CLASS_COLOR << "ScavTrap "
			  << NAME_COLOR << this->_name
			  << R << " Destructor called"
			  << RST << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << CLASS_COLOR << "ScavTrap "
			  << G << "Copy assignment operator called"
			  << RST << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_guardMode = other._guardMode;
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_HP == 0)
	{
		std::cout << CLASS_COLOR << "ScavTrap "
				  << NAME_COLOR << this->_name
				  << RST << " cannot "
				  << DMG_COLOR << "attack"
				  << RST << ", because it's dead!"
				  << std::endl;
		return ;
	}
	else if (this->_SP == 0)
	{
		std::cout << CLASS_COLOR << "ScavTrap "
				  << NAME_COLOR << this->_name
				  << RST << " cannot "
				  << DMG_COLOR << "attack"
				  << RST << ", because it doesn't have energy!"
				  << std::endl;
		return ;
	}
	std::cout << CLASS_COLOR << "ScavTrap "
			  << NAME_COLOR << this->_name
			  << DMG_COLOR << " attacks "
			  << NAME_COLOR << target
			  << DMG_COLOR << ", causing "
			  << NUM_COLOR << this->_AD
			  << DMG_COLOR << " points of damage!"
			  << RST << std::endl;

	this->_SP--;
}

void ScavTrap::guardGate()
{
	if (_guardMode == true)
	{
		std::cout << CLASS_COLOR << "ScavTrap "
				  << NAME_COLOR << this->_name
				  << RST << " already in "
				  << GUARD_COLOR << "Gate Keeper mode!"
				  << RST << std::endl;
		return ;
	}
	else if (this->_HP == 0)
	{
		std::cout << CLASS_COLOR << "ScavTrap "
				  << NAME_COLOR << this->_name
				  << RST << " cannot enter "
				  << GUARD_COLOR << "Gate Keeper mode"
				  << RST << ", because it's dead!"
				  << std::endl;
		return ;
	}
	else if (this->_SP == 0)
	{
		std::cout << CLASS_COLOR << "ScavTrap "
				  << NAME_COLOR << this->_name
				  << RST << " cannot enter "
				  << GUARD_COLOR << "Gate Keeper mode"
				  << RST << ", because it doesn't have energy!"
				  << std::endl;
		return ;
	}
	std::cout << CLASS_COLOR << "ScavTrap "
			  << NAME_COLOR << this->_name
			  << GUARD_COLOR << " is now in Gate Keeper mode! "
			  << "I don't know what that means."
			  << RST << std::endl;
	this->_guardMode = true;
	this->_SP--;
}

void ScavTrap::_initScavStats()
{
	this->_HP = 100;
	this->_SP = 50;
	this->_AD = 20;
	this->_type = "ScavTrap";
	this->_guardMode = false;
}