/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:14:50 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/31 18:09:31 by frbranda         ###   ########.fr       */
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
	std::cout << BOLD_M << "[DEBUG]" << RST << std::endl;
	std::cout << M
			  << "I love having extra bacon for my "
			  << "7XL-double-cheese-triple-pickle-special-ketchup burger. "
			  << "I really do!\n" << RST << std::endl;
}

void	Harl::info(void)
{
	std::cout << BOLD_C << "[INFO]" << RST << std::endl;
	std::cout << C
			  << "I cannot believe adding extra bacon costs more money. "
			  << "You didn't put enough bacon in my burger! If you did, "
			  << "I wouldn't be asking for more!\n"
			  << RST << std::endl;
}

void	Harl::warning(void)
{
	std::cout << BOLD_Y << "[WARNING]" << RST << std::endl;
	std::cout << Y
			  << "I think I deserve to have some extra bacon for free. "
			  << "I've been coming for years, whereas you started working "
			  << "here just last month.\n" 
			  << RST << std::endl;
}

void	Harl::error(void)
{
	std::cout << BOLD_R << "[ERROR]" << RST << std::endl;
	std::cout << R
			  << "This is unacceptable! I want to speak to the manager now.\n"
			  << RST << std::endl;
}

void Harl::switchFilter(int levelIndex)
{
	switch(levelIndex)
	{
		case DEBUG:
			this->debug();
		case INFO:
			this->info();
		case WARNING:
			this->warning();
		case ERROR:
			this->error();
			break ;
		default:
			std::cerr << BOLD_R
					  << "[ Probably complaining about "
					  << "insignificant problems ]"
					  << RST << std::endl;
			break;
	}
}

void Harl::complain( std::string level )
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int	levelIndex = -1;
	
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			levelIndex = i;
			break ;
		}
	}
	
	switchFilter(levelIndex);
}
