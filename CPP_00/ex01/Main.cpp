/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:47:16 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/16 17:15:31 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main (void)
{
	PhoneBook	phonebook;
	std::string	input;

	while (true)
	{
		std::cout << BOLD_W << "Enter a Command (ADD, SEARCH, EXIT): " << RST;
		if (!std::getline(std::cin, input))
		{
			std::cout << CLEAR;
			std::cout << WR_BG << "💥💥💥 BOOM! 💥💥💥" << std::endl;
			std::cout << "💣 Getline failed? " << RST << std::endl;
			std::cout << BOLD_R << "  WHAT DID YOU DO? " << RST << std::endl;
			break ;
		}
		std::cout << CLEAR;
		if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
		{
			std::cout << BOLD_M << "Bye Bye! :c" << RST << std::endl;
			break ;
		}
		else
		{
			std::cout << BOLD_R << " HUH???????? CAN'T YOU READ?\n"
			<< BOLD_C << " --> (ADD, SEARCH, EXIT) <-- " << RST << std::endl;
		}
	}
	return (0);
}