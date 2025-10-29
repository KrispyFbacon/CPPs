/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:40:11 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/29 12:37:04 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL)
{
	std::cout << G << "HumanB " << this->_name << " Created!"
			  << RST << std::endl;
}

HumanB::~HumanB()
{
	std::cout << R << "HumanB " << this->_name << " Destroyed!"
			  << RST << std::endl;
}

void	HumanB::setWeapon(Weapon& weaponType)
{
	this->_weapon = &weaponType;
}

void	HumanB::attack()
{
	if (this->_weapon)
	{
		std::cout << HUMAN << this->_name 
				  << RST << " attacks with their "
				  << WEAPON << this->_weapon->getType()
				  << RST << std::endl;
	}
	else
	{
		std::cout << HUMAN << this->_name << RST
				  << " tried to attack but has no weapon " << std::endl;
	}
}