/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:37:10 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/16 18:20:20 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << G << "Phonebook created" << RST << std::endl;
}

void	PhoneBook::add()
{
	std::string input;
	int	index = this->_i % 8;
	
	std::cout << C << "Adding contact" << RST << std::endl;
	std::cout << BOLD_W << "Enter First Name: " << RST;
	//TODO both !getline and check empty
	std::getline(std::cin, input);
	
}

void	PhoneBook::search()
{
	std::cout << C << "Search for contact" << RST << std::endl;
}