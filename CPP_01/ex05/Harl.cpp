/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:14:50 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/30 11:36:08 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

Harl::Harl()
{
	std::cout << G << "Harl Created!" << RST << std::endl;
}

Harl::~Harl()
{
	std::cout << R << "Harl Destroyed!" << RST << std::endl;
}

void	Harl::debug(void)
{
	std::cout << BOLD_Y << "[DEBUG]" << RST << std::endl;
	std::cout << "I love having extra bacon for my "
			  << "7XL-double-cheese-triple-pickle-special-ketchup burger. "
			  << "I really do!" << RST << std::endl;
}

void	Harl::info(void)
{
	std::cout << BOLD_C << "[INFO]" << RST << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. "
			  << "You didn't put enough bacon in my burger! If you did, "
			  << "I wouldn't be asking for more!" << RST << std::endl;
}

void	Harl::warning(void)
{
	std::cout << BOLD_Y << "[WARNING]" << RST << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. "
			  << "I've been coming for years, whereas you started working "
			  << "here just last month." << RST << std::endl;
}

void	Harl::error(void)
{
	std::cout << BOLD_R << "[ERROR]" << RST << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." 
			  << RST << std::endl;
}
