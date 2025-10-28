/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:15 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/28 15:48:03 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name("")
{
	std::cout << G  << "Default Zombie Created" << RST << std::endl;
}

Zombie::Zombie(const std::string &name)
{
	this->_name = name;
	
	std::cout << G << "Zombie " 
			  << Z_COLOR << this->_name
			  << G << " Created!"
			  << RST << std::endl;
}

Zombie::~Zombie()
{
	std::cout << R << "Zombie " 
			  << Z_COLOR << this->_name
			  << R << " Destroyed!"
			  << RST << std::endl;
}

void	Zombie::setName(const std::string &name)
{
	this->_name = name;
}

std::string Zombie::getName() const
{
	return this->_name;
}

void Zombie::announce( void )
{
	std::cout << Z_COLOR << this->_name
			  << RST << ": BraiiiiiiinnnzzzZ..."
			  << std::endl;
}

