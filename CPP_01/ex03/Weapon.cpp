/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:15 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/07 14:40:21 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : _type(type)
{
	std::cout << G << "Weapon " << this->_type << " Created!"
			  << RST << std::endl;
}

Weapon::~Weapon()
{
	std::cout << R << "Weapon " << this->_type << " Destroyed!"
			  << RST << std::endl;
}

void	Weapon::setType(const std::string &type)
{
	this->_type = type;
}

std::string&	Weapon::getType() const
{
	//TODO fix this
	return this->_type;
}