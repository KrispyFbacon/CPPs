/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:55:41 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/04 17:24:20 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void test1_ValidFormCreation()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 1: Valid Form Creation           ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try 
	{
		Intern someRandomIntern;
		AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch (const std::exception& e) 
	{
		std::cerr << R << "Exception: " << O << e.what() << RST << std::endl;
	}
}

void test2_AllThreeForms()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 2: All Three Forms               ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try 
	{
		Intern intern;
		
		AForm* form1 = intern.makeForm("presidential pardon", "Arthur Dent");
		std::cout << *form1 << std::endl;
		delete form1;
		
		std::cout << std::endl;
		
		AForm* form2 = intern.makeForm("robotomy request", "Marvin");
		std::cout << *form2 << std::endl;
		delete form2;
		
		std::cout << std::endl;
		
		AForm* form3 = intern.makeForm("shrubbery creation", "Garden");
		std::cout << *form3 << std::endl;
		delete form3;
	}
	catch (const std::exception& e) 
	{
		std::cerr << R << "Exception: " << O << e.what() << RST << "\n";
	}
}

void test3_InvalidFormName()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 3: Invalid Form Name             ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try 
	{
		Intern intern;
		AForm* form = intern.makeForm("unknown form", "Target");
		delete form;
	}
	catch (const std::exception& e) 
	{
		std::cerr << R << "Exception: " << O << e.what() << RST << std::endl;
	}
}

void test4_CaseSensitivityCheck()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 4: Case Sensitivity Check        ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try 
	{
		Intern intern;
		
		AForm* form = intern.makeForm("Presidential Pardon", "Target");
		delete form;
	}
	catch (const std::exception& e) 
	{
		std::cerr << R << "Exception: " << O << e.what() << RST << std::endl;
	}
}

void test5_MultipleInterns()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 5: Multiple Interns              ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try 
	{
		Intern intern1;
		Intern intern2;
		Intern intern3;
		
		AForm* f1 = intern1.makeForm("robotomy request", "Bob");
		AForm* f2 = intern2.makeForm("shrubbery creation", "Alice");
		AForm* f3 = intern3.makeForm("presidential pardon", "Charlie");
		
		std::cout << *f1 << std::endl;
		std::cout << *f2 << std::endl;
		std::cout << *f3 << std::endl;
		
		delete f1;
		delete f2;
		delete f3;
	}
	catch (const std::exception& e) 
	{
		std::cerr << R << "Exception: " << O << e.what() << RST << std::endl;
	}
}

int main()
{
	test1_ValidFormCreation();
	test2_AllThreeForms();
	test3_InvalidFormName();
	test4_CaseSensitivityCheck();
	test5_MultipleInterns();
	
	return (0);
}