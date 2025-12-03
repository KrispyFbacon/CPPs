/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:05:40 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/03 18:48:51 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	test1_validFormCreation()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 1: Valid Form Creation           ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try
	{
		Bureaucrat bacon("Bacon", 1);
		
		AForm* Shrub = new ShrubberyCreationForm("Home");
		AForm* Robot = new RobotomyRequestForm("Garden");
		AForm* Pres = new PresidentialPardonForm ("Council");
		
		std::cout << bacon << std::endl;
		std::cout << *Shrub << std::endl;
		std::cout << *Robot << std::endl;
		std::cout << *Pres << std::endl;

		std::cout << std::endl;

		bacon.signForm(*Shrub);
		bacon.signForm(*Robot);
		bacon.signForm(*Pres);

		std::cout << std::endl;

		bacon.executeForm(*Shrub);
		bacon.executeForm(*Robot);
		bacon.executeForm(*Pres);
		
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}


int main ()
{
	std::srand(std::time(NULL));
	
	test1_validFormCreation();

	return 0;
}

