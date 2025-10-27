/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:37:10 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/27 14:10:32 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _index(0)
{
	std::cout << G << "Phonebook Ready!" << RST << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << R << "Phonebook destroyed" << RST << std::endl;
}

void	PhoneBook::add()
{
	std::string	input[5];
	int			index = this->_index % MAX_CONTACTS;
	
	std::cout << BOLD_C << "Adding contact" << RST << std::endl;

	input[0] = getInput(P_FIRST);
	if (input[0].empty())
		return;

	input[1] = getInput(P_SECOND);
	if (input[1].empty())
		return;

	input[2] = getInput("Enter Nick Name: ");
	if (input[2].empty())
		return;
	
	input[3] = getInput(P_PHONE);
	if (input[3].empty())
		return;

	input[4] = getInput("Enter Darkest Secret: ");
	if (input[4].empty())
		return;

	this->contact[index].setFirstName(input[0]);
	this->contact[index].setLastName(input[1]);
	this->contact[index].setNickName(input[2]);
	this->contact[index].setPhoneNumber(input[3]);
	this->contact[index].setDarkestSecret(input[4]);
	
	this->_index++;
	Printer::added();
}

void	PhoneBook::search()
{
	std::string	index;
	int			i;
	
	if (this->_index == 0)
	{
		std::cout << BOLD_R << "No contacts saved yet!" << RST << std::endl;
		return;
	}
	
	Printer::startTable();
	for (i = 0; i < std::min(this->_index, MAX_CONTACTS); i++)
	{
		std::cout << BOLD_W << "|" << BOLD_Y
				  << std::setw(10) << i
				  << BOLD_W << "|" << BOLD_Y
				  << formatField(this->contact[i].getFirstName())
				  << BOLD_W << "|" << BOLD_Y
				  << formatField(this->contact[i].getLastName())
				  << BOLD_W << "|" << BOLD_Y
				  << formatField(this->contact[i].getNickName())
				  << BOLD_W << "|" << RST
				  << std::endl;
	}
	index = getInput("Insert an index to view details: ");
	if (!isValidIndex(index))
		return ;

	i = index[0] - '0';
	displayContact(i);
}


std::string PhoneBook::getInput(const std::string &prompt)
{
	std::string input;
		
	while (true)
	{
		Printer::prompt(prompt);
		
		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof())
			{
				std::cin.clear();
				std::cout << std::endl;
				return "";
			}
		}
		
		input = trim(input);
		
		if (input.empty())
		{
			Printer::empty();
			continue ;
		}

		if (prompt == P_PHONE && !isValidNumber(input))
		{
			Printer::error("Invalid phone number! Use only digits.");
			continue ;
		}

		if ((prompt == P_FIRST || prompt == P_SECOND) && !isValidName(input))
		{
			Printer::error("Invalid name! Use only letters.");
			continue ;
		}
		
		return input;
	}
}

std::string PhoneBook::formatField(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + '.');
	return (std::string(10 - str.length(), ' ') + str);
}

bool PhoneBook::isValidIndex(const std::string &index) const
{
	int	i;
	
	if (index.empty())
		return false;
		
	if (index.size() != 1 || !std::isdigit(index[0]))
	{
		std::cout << BOLD_R << "Invalid input!" << RST << std::endl;
		return false;
	}
	
	i = index[0] - '0';
	if (i < 0 || i >= std::min(this->_index, MAX_CONTACTS))
	{
		std::cout << BOLD_R << "No contact at this index!" << RST << std::endl;
		return false;
	}
	return true;
}

void PhoneBook::displayContact(const int &index) const
{
	const int width = 13;

	std::cout << BOLD_G << "\n=== Contact Details ===" << RST << std::endl;

	Printer::field("First Name:", this->contact[index].getFirstName(), width);
	Printer::field("Last Name:", this->contact[index].getLastName(), width);
	Printer::field("Nickname:", this->contact[index].getNickName(), width);
	Printer::field("Phone Number:", this->contact[index].getPhoneNumber(), width);
	Printer::field("Dark Secret:", this->contact[index].getDarkestSecret(), width);
}
