/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:47:16 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/24 13:19:17 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main (void)
{
	PhoneBook	phonebook;
	std::string	input;

	while (true)
	{
		Printer::prompt("Enter a Command (ADD, SEARCH, EXIT): ");
		if (!std::getline(std::cin, input))
		{
			std::cin.clear();
			std::cout << std::endl;
			Printer::boom();
			break ;
		}
		CLEAR_();
		if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
		{
			Printer::exit();
			break ;
		}
		else
			Printer::invalidCommand();
	}
	return (0);
}