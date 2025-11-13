/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/13 17:50:24 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
			: ClapTrap("unknow_clap_name"), ScavTrap(),
				FragTrap(), _name("unknown")
{
	_initDiamondStats();
	std::cout << CLASS_COLOR << "DiamondTrap "
			  << G << "Default Constructor called"
			  << RST << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
			: ClapTrap(name + "_clap_name"), ScavTrap(name),
				FragTrap(name), _name(name)
{
	_initDiamondStats();
	std::cout << CLASS_COLOR << "DiamondTrap "
			  << NAME_COLOR << this->_name
			  << G << " Constructor called"
			  << RST << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other._name), ScavTrap(other._name),
		FragTrap(other._name), _name(other._name)
{
	std::cout << CLASS_COLOR << "DiamondTrap "
			  << NAME_COLOR << this->_name
			  << G << " Copy Constructor called"
			  << RST << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << CLASS_COLOR << "DiamondTrap "
			  << NAME_COLOR << this->_name
			  << R << " Destructor called"
			  << RST << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << CLASS_COLOR << "DiamondTrap "
			  << G << "Copy assignment operator called"
			  << RST << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
	if (this->_HP == 0)
	{
		std::cout << CLASS_COLOR << "DiamondTrap "
				  << NAME_COLOR << this->_name
				  << RST << " cannot "
				  << DMG_COLOR << "attack"
				  << RST << ", because it's dead!"
				  << std::endl;
		return ;
	}
	else if (this->_SP == 0)
	{
		std::cout << CLASS_COLOR << "DiamondTrap "
				  << NAME_COLOR << this->_name
				  << RST << " cannot "
				  << DMG_COLOR << "attack"
				  << RST << ", because it doesn't have energy!"
				  << std::endl;
		return ;
	}
	std::cout << CLASS_COLOR << "DiamondTrap "
			  << NAME_COLOR << this->_name
			  << DMG_COLOR << " attacks "
			  << NAME_COLOR << target
			  << DMG_COLOR << ", causing "
			  << NUM_COLOR << this->_AD
			  << DMG_COLOR << " points of damage!"
			  << RST << std::endl;
	
	this->_SP--;
}

void DiamondTrap::whoAmI()
{
	std::cout << WHOAMI_COLOR << "DiamondTrap name: "
			  << NAME_COLOR << this->_name
			  << WHOAMI_COLOR << ", ClapTrap name: " 
			  << NAME_COLOR << ClapTrap::_name 
			  << RST << std::endl;
}

void DiamondTrap::_initDiamondStats()
{
	this->_HP = FragTrap::_HP;
	//this->_SP = ScavTrap::_SP;
	this->_SP = 50;
	this->_AD = FragTrap::_AD;
	this->_type = "DiamondTrap";
}