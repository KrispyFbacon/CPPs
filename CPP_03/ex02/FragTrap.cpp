/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/12 18:14:53 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default FragTrap")
{
	_initFragStats();
	std::cout << CLASS_COLOR << "FragTrap "
			  << G << "Default Constructor called"
			  << RST << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_initFragStats();
	std::cout << CLASS_COLOR << "FragTrap "
			  << NAME_COLOR << this->_name
			  << G << " Constructor called"
			  << RST << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << CLASS_COLOR << "FragTrap "
			  << NAME_COLOR << this->_name
			  << G << " Copy Constructor called"
			  << RST << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << CLASS_COLOR << "FragTrap "
			  << NAME_COLOR << this->_name
			  << R << " Destructor called"
			  << RST << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << CLASS_COLOR << "FragTrap "
			  << G << "Copy assignment operator called"
			  << RST << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

void FragTrap::attack(const std::string& target)
{
	if (this->_HP == 0)
	{
		std::cout << CLASS_COLOR << "FragTrap "
				  << NAME_COLOR << this->_name
				  << RST << " cannot "
				  << DMG_COLOR << "attack"
				  << RST << ", because it's dead!"
				  << std::endl;
		return ;
	}
	else if (this->_SP == 0)
	{
		std::cout << CLASS_COLOR << "FragTrap "
				  << NAME_COLOR << this->_name
				  << RST << " cannot "
				  << DMG_COLOR << "attack"
				  << RST << ", because it doesn't have energy!"
				  << std::endl;
		return ;
	}
	std::cout << CLASS_COLOR << "FragTrap "
			  << NAME_COLOR << this->_name
			  << DMG_COLOR << " attacks "
			  << NAME_COLOR << target
			  << DMG_COLOR << ", causing "
			  << NUM_COLOR << this->_AD
			  << DMG_COLOR << " points of damage!"
			  << RST << std::endl;
	
	this->_SP--;
}

void FragTrap::highFivesGuys()
{
	if (this->_HP == 0)
	{
		std::cout << CLASS_COLOR << "FragTrap "
				  << NAME_COLOR << this->_name
				  << RST << " cannot "
				  << HIGHFIVE_COLOR << "High-Five"
				  << RST << ", because it's dead! :("
				  << std::endl;
		return ;
	}
	else if (this->_SP == 0)
	{
		std::cout << CLASS_COLOR << "FragTrap "
				  << NAME_COLOR << this->_name
				  << RST << " cannot "
				  << HIGHFIVE_COLOR << "High-Five"
				  << RST << ", because it doesn't have energy! :("
				  << std::endl;
		return ;
	}
	std::cout << CLASS_COLOR << "FragTrap "
			  << NAME_COLOR << this->_name
			  << HIGHFIVE_COLOR << " is trying to High-Five but no one is there "
			  << "Wow what a loser! 💀"
			  << RST << std::endl;
}

void FragTrap::_initFragStats()
{
	this->_HP = 100;
	this->_SP = 100;
	this->_AD = 30;
	this->_type = "FragTrap";
}