/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:22:56 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/18 16:19:18 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << CLASS_COLOR << "Brain "
			  << G << "Default Constructor called"
			  << RST << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "Empty thought";
}

Brain::Brain(const Brain& other)
{
	std::cout << CLASS_COLOR << "Brain "
			  << G << "Copy Constructor called"
			  << RST << std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cout << CLASS_COLOR << "Brain "
			  << R << "Destructor called"
			  << RST << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << CLASS_COLOR << "Brain "
			  << G << "Copy assignment operator called"
			  << RST << std::endl;
	if (this != &other)
	{
		for (int i = 0 ; i < 100; ++i)
			this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}


void	Brain::setIdea(int index, const std::string& idea)
{
	this->_ideas[index] = idea;
}

const std::string& Brain::getIdea(int index) const
{
	return this->_ideas[index];
}