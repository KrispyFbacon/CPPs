/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:22:05 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/29 12:36:58 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weaponType) 
	: _name(name), _weapon(weaponType)
{
	std::cout << G << "HumanA " << this->_name << " Created!"
			  << RST << std::endl;
}

HumanA::~HumanA()
{
	std::cout << R << "HumanA " << this->_name << " Destroyed!"
			  << RST << std::endl;
}

void	HumanA::attack()
{
	std::cout << HUMAN << this->_name 
			  << RST << " attacks with their "
			  << WEAPON << this->_weapon.getType()
			  << RST << std::endl;
}