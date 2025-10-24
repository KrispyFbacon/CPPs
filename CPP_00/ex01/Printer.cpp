/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:54:00 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/24 18:11:18 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Printer.hpp"

void Printer::prompt(const std::string &prompt)
{
	std::cout << BOLD_W << prompt << RST;
}

// Errors
void Printer::error(const std::string &error)
{
	std::cout << BOLD_R << error << RST << std::endl;
}

void Printer::invalidCommand()
{
	std::cout << BOLD_R << "  HUH????? CAN'T YOU READ?\n"
			  << BOLD_C << "--> (ADD, SEARCH, EXIT) <--"
			  << RST << std::endl;
}

void Printer::boom()
{
	//std::cout << CLEAR;
	CLEAR_();
	std::cout << WR_BG << "💥💥💥 BOOM! 💥💥💥" << std::endl;
	std::cout << "💣 Getline failed? " << RST << std::endl;
	std::cout << BOLD_R << " WHAT DID YOU DO? " << RST << std::endl;
}

void Printer::empty()
{
	std::cout << BOLD_R << "This field can't be empty!"
			  << RST << std::endl;
}

// Add
void Printer::added()
{
	std::cout << BOLD_G << "✅ Contact added successfully!" << RST << std::endl;
}

// Search
void Printer::startTable()
{
	std::cout << BOLD_W
			  << "|" << BOLD_C << std::setw(10) << "Index" << BOLD_W
			  << "|" << BOLD_C << std::setw(10) << "First name" << BOLD_W
			  << "|" << BOLD_C << std::setw(10) << "Last name" << BOLD_W
			  << "|" << BOLD_C << std::setw(10) << "Nickname" << BOLD_W
			  << "|" << BOLD_C << RST <<std::endl;
}

// exit
void Printer::exit()
{
	std::cout << BOLD_M << "Bye Bye! :c" << RST << std::endl;
}