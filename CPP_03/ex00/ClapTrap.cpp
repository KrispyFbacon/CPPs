/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/11 18:16:20 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("unknown") , _HP(10), _SP(10), _AD(10)
{
	std::cout << CLASS_COLOR << "ClapTrap " << G << "Default Constructor called"
			  << RST << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _HP(10), _SP(10), _AD(10)
{
	std::cout << CLASS_COLOR << "ClapTrap " << G << "Constructor called"
			  << RST << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << CLASS_COLOR << "ClapTrap " << G << "Copy Constructor called"
			  << RST << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << CLASS_COLOR << "ClapTrap " << R << "Destructor called"
			  << RST << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << CLASS_COLOR << "ClapTrap " << Y << "Copy assignment operator called"
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
				  << RST << " cannot attack, because it's dead!"
				  << std::endl;
		return ;
	}
	else if (this->_SP == 0)
	{
		std::cout << CLASS_COLOR << "ClapTrap "
				  << NAME_COLOR << this->_name
				  << RST << " cannot attack, because it doesn't have energy"
				  << std::endl;
		return ;
	}
	std::cout << CLASS_COLOR << "ClapTrap "
			  << NAME_COLOR << this->_name
			  << DMG_COLOR << " attacks "
			  << NAME_COLOR << target << RST ", "
			  << DMG_COLOR << "causing "
			  << RGB(255, 165, 0) << this->_AD
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
			  << RGB(255, 165, 0) << amount
			  << DMG_COLOR << " hit points"
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
				  << RST << " cannot repair, because it's dead!"
				  << std::endl;
		return ;
	}
	else if (this->_SP == 0)
	{
		std::cout << CLASS_COLOR << "ClapTrap "
				  << NAME_COLOR << this->_name
				  << RST << " cannot repair, because it doesn't have energy!"
				  << std::endl;
		return ;
	}
	std::cout << CLASS_COLOR << "ClapTrap "
			  << NAME_COLOR << this->_name
			  << HEAL_COLOR << " repairs itself, recovering "
			  << RGB(255, 165, 0) << amount
			  << HEAL_COLOR  << " health points!"
			  << RST << std::endl;
	
	this->_HP += amount;
	this->_SP--;
}

const std::string& ClapTrap::getName() const
{
	return this->_name;
}