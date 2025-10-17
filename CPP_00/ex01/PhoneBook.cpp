/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:37:10 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/17 11:59:20 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _i(0)
{
	std::cout << G << "Phonebook Ready!" << RST << std::endl;
}

void	PhoneBook::add()
{
	std::string	input;
	int			index = this->_i % 8;
	
	std::cout << BOLD_C << "Adding contact" << RST << std::endl;

	input = getInput("Enter First Name: ");
	if (input.empty())
		return;
	this->contact[index].setFirstName(input);

	input = getInput("Enter Last Name: ");
	if (input.empty())
		return;
	this->contact[index].setLastName(input);

	input = getInput("Enter Nick Name: ");
	if (input.empty())
		return;
	this->contact[index].setNickName(input);
	
	input = getInput("Enter Phone Number: ");
	if (input.empty())
		return;
	this->contact[index].setPhoneNumber(input);

	input = getInput("Enter Darkest Secret: ");
	if (input.empty())
		return;
	this->contact[index].setDarkestSecret(input);
	this->_i++;
	std::cout << BOLD_G << "✅ Contact added successfully!" << RST << std::endl;
	// this->contact[index].setFirstName(getInput("Enter First Name: "));
	// if (this->contact[index].getFirstName().empty())
	// 	return;
}

void	PhoneBook::search()
{
	if (this->_i == 0)
	{
		std::cout << BOLD_R << "No contacts saved yet!" << RST << std::endl;
		return;
	}
	Printer::startTable();
}

std::string	PhoneBook::getInput(const std::string &prompt)
{
	std::string input;

	while (true)
	{
		Printer::prompt(prompt);
		if (!std::getline(std::cin, input))
		{
			std::cin.clear();
			std::cout << std::endl;
			return "";
		}
		if (!input.empty())
			return input;
		Printer::empty();
	}
}
