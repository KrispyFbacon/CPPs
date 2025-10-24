/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:56:01 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/24 13:05:28 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	std::cout << G << "Contact slot initialized." << RST << std::endl;
}

Contact::~Contact()
{
	std::cout << R << "Contact destroyed" << RST << std::endl;
}

// Setters
void	Contact::setFirstName(const std::string FirstName)
{
	this->_FirstName = FirstName;
}

void	Contact::setLastName(const std::string LastName)
{
	this->_LastName = LastName;
}

void	Contact::setNickName(const std::string NickName)
{
	this->_NickName = NickName;
}

void	Contact::setPhoneNumber(const std::string PhoneNumber)
{
	this->_PhoneNumber = PhoneNumber;
}

void	Contact::setDarkestSecret(const std::string DarkestSecret)
{
	this->_DarkestSecret = DarkestSecret;
}


//Getters
std::string	Contact::getFirstName() const
{
	return this->_FirstName;
}

std::string	Contact::getLastName() const
{
	return this->_LastName;
}

std::string	Contact::getNickName() const
{
	return this->_NickName;
}

std::string	Contact::getPhoneNumber() const
{
	return this->_PhoneNumber;
}

std::string	Contact::getDarkestSecret() const
{
	return this->_DarkestSecret;
}
