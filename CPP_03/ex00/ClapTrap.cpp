/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/12 13:31:18 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("unknown") , _HP(10), _SP(10), _AD(10)
{
	std::cout << CLASS_COLOR << "ClapTrap " 
			  << G << "Default Constructor called"
			  << RST << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _HP(10), _SP(10), _AD(10)
{
	std::cout << CLASS_COLOR << "ClapTrap "
			  << NAME_COLOR << this->_name
			  << G << " Constructor called"
			  << RST << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << CLASS_COLOR << "ClapTrap "
			  << NAME_COLOR << this->_name
			  << G << " Copy Constructor called"
			  << RST << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << CLASS_COLOR << "ClapTrap "
			  << NAME_COLOR << this->_name
			  << R << " Destructor called"
			  << RST << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << CLASS_COLOR << "ClapTrap "
			  << G << "Copy assignment operator called"
			  << RST << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_HP = other._HP;
		this->_SP = other._SP;
		this->_AD = other._AD;
	}
	return (*this);
}


void ClapTrap::attack(const std::string& target)
{
	if (this->_HP == 0)
	{
		std::cout << CLASS_COLOR << "ClapTrap "
				  << NAME_COLOR << this->_name
				  << RST << " cannot "
				  << DMG_COLOR << "attack"
				  << RST << ", because it's dead!"
				  << std::endl;
		return ;
	}
	else if (this->_SP == 0)
	{
		std::cout << CLASS_COLOR << "ClapTrap "
				  << NAME_COLOR << this->_name
				  << RST << " cannot "
				  << DMG_COLOR << "attack"
				  << RST << ", because it doesn't have energy!"
				  << std::endl;
		return ;
	}
	std::cout << CLASS_COLOR << "ClapTrap "
			  << NAME_COLOR << this->_name
			  << DMG_COLOR << " attacks "
			  << NAME_COLOR << target
			  << DMG_COLOR << ", causing "
			  << NUM_COLOR << this->_AD
			  << DMG_COLOR << " points of damage!"
			  << RST << std::endl;
	
	this->_SP--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_HP == 0)
	{
		std::cout << CLASS_COLOR << "ClapTrap "
				  << NAME_COLOR << this->_name
				  << RST << " STOP! STOP! HE IS ALREADY DEAD! "
				  << "SWEET JESUS, LORD HAVE MERCY, MY BABY!"
				  << std::endl;
		return ;
	}
	std::cout << CLASS_COLOR << "ClapTrap "
			  << NAME_COLOR << this->_name
			  << DMG_COLOR << " takes "
			  << NUM_COLOR << amount
			  << DMG_COLOR << " hit points!"
			  << RST << std::endl;
	
	if (amount >= this->_HP)
		this->_HP = 0;
	else
		this->_HP -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_HP == 0)
	{
		std::cout << CLASS_COLOR << "ClapTrap "
				  << NAME_COLOR << this->_name
				  << RST << " cannot "
				  << HEAL_COLOR << "repair"
				  << RST << ", because it's dead!"
				  << std::endl;
		return ;
	}
	else if (this->_SP == 0)
	{
		std::cout << CLASS_COLOR << "ClapTrap "
				  << NAME_COLOR << this->_name
				  << RST << " cannot "
				  << HEAL_COLOR << "repair"
				  << RST << ", because it doesn't have energy!"
				  << std::endl;
		return ;
	}
	std::cout << CLASS_COLOR << "ClapTrap "
			  << NAME_COLOR << this->_name
			  << HEAL_COLOR << " repairs itself, recovering "
			  << NUM_COLOR << amount
			  << HEAL_COLOR  << " health points!"
			  << RST << std::endl;
	
	this->_HP += amount;
	this->_SP--;
}

const unsigned int& ClapTrap::getAD() const
{
	return this->_AD;
}

const unsigned int& ClapTrap::getSP() const
{
	return this->_SP;
}