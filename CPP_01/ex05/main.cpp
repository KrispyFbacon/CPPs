/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:28:27 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/30 12:32:28 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static std::string	toUpperCase(const std::string& str)
{
	std::string result = str;
	
	for (size_t i = 0; i < result.length(); i++)
		result[i] = std::toupper(result[i]);
	return (result);
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << BOLD_R << "\nError\nInvalid argument count\n"
				  << RST << std::endl;
		std::cout << BOLD_Y << "Usage:  "
				  << RST << argv[0] << " [level display]" << RST << std::endl;
		std::cout << BOLD_Y << "Choose: "
				  << RST << "[DEBUG], [INFO], [WARNING], [ERROR]\n"
				  << RST << std::endl;
		return (1); 
	}
	
	//Harl harl();
	
	std::string argument = argv[1];
	std::string input = toUpperCase(argument);

}