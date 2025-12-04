/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:55:41 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/04 14:26:15 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

std::string intToString(int num)
{
	std::stringstream ss;
	ss << num;
	return ss.str();
}

void test1_validFormCreation()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 1: Valid Form Creation           ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try
	{
		Bureaucrat bacon("Bacon", 1);
		ShrubberyCreationForm shrub("Home");
		RobotomyRequestForm robot("Garden");
		PresidentialPardonForm pres("Council");
		
		std::cout << bacon << std::endl;
		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << pres << std::endl;
		std::cout << std::endl;

		bacon.signForm(shrub);
		bacon.signForm(robot);
		bacon.signForm(pres);
		std::cout << std::endl;

		bacon.executeForm(shrub);
		bacon.executeForm(robot);
		bacon.executeForm(pres);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void test2_WrongFormName()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test2: Wrong Form Name                ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try 
	{
		Intern someRandomIntern;
		AForm* f = someRandomIntern.makeForm("robotomy request", "Bender");
	}
	catch (const std::exception& e) 
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}
}

int main()
{
	test1_validFormCreation();
	test2_WrongFormName();
	
	return (0);
}