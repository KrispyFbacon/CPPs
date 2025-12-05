/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:55:41 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/05 15:46:59 by frbranda         ###   ########.fr       */
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
	std::cout << std::endl;
}

void test2_AllThreeForms()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 2: All Three Forms               ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try 
	{
		Intern intern;
		Bureaucrat president("President", 1);
		
		AForm* form1 = intern.makeForm("presidential pardon", "Arthur Dent");
		std::cout << *form1 << std::endl;
		president.signForm(*form1);
		president.executeForm(*form1);
		delete form1;
		
		std::cout << std::endl;
		
		AForm* form2 = intern.makeForm("robotomy request", "Marvin");
		std::cout << *form2 << std::endl;
		president.signForm(*form2);
		president.executeForm(*form2);
		delete form2;
		
		std::cout << std::endl;
		
		AForm* form3 = intern.makeForm("shrubbery creation", "Garden");
		std::cout << *form3 << std::endl;
		president.signForm(*form3);
		president.executeForm(*form3);
		delete form3;
	}
	catch (const std::exception& e) 
	{
		std::cerr << R << "Exception: " << O << e.what() << RST << "\n";
	}
	std::cout << std::endl;
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
	std::cout << std::endl;
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
	std::cout << std::endl;
}

void test5_GradeTooLowToSign()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 5: Grade Too Low to Sign         ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try 
	{
		Intern intern;
		Bureaucrat lowGrade("Intern", 150);
		
		AForm* form = intern.makeForm("presidential pardon", "Target");
		std::cout << *form << std::endl;
		

		lowGrade.signForm(*form);
		lowGrade.executeForm(*form);
		
		delete form;
	}
	catch (const std::exception& e) 
	{
		std::cerr << R << "Exception: " << O << e.what() << RST << std::endl;
	}
	std::cout << std::endl;
}

void test6_GradeTooLowToExecute()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 6: Grade Too Low to Execute      ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try 
	{
		Intern intern;
		Bureaucrat bacon("Manager", 25); // Can sign (grade 25)
		
		AForm* form = intern.makeForm("presidential pardon", "Target");
		std::cout << *form << std::endl;
		
		// Sign successfully
		bacon.signForm(*form);
		
		// Try to execute (should fail - needs grade 5)
		bacon.executeForm(*form);
		
		delete form;
	}
	catch (const std::exception& e) 
	{
		std::cerr << R << "Exception: " << O << e.what() << RST << std::endl;
	}
	std::cout << std::endl;
}

void test6_ExecuteUnsignedForm()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 7: Execute Unsigned Form         ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try 
	{
		Intern intern;
		Bureaucrat boss("Boss", 1);
		
		AForm* form = intern.makeForm("shrubbery creation", "Home");
		std::cout << *form << std::endl;
		
		// Try to execute without signing (should fail)
		boss.executeForm(*form);
		
		delete form;
	}
	catch (const std::exception& e) 
	{
		std::cerr << R << "Exception: " << O << e.what() << RST << std::endl;
	}
	std::cout << std::endl;
}

void test7_RobotomyRandomness()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 8: Robotomy Randomness (5 tries) ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try 
	{
		Intern intern;
		Bureaucrat boss("Boss", 1);
		
		for (int i = 1; i <= 5; i++)
		{
			std::stringstream ss;
			ss << "Target" << i;
			std::string target = ss.str();
			
			std::cout << "\n--- Attempt " << i << " ---" << std::endl;
			AForm* form = intern.makeForm("robotomy request", target);
			
			boss.signForm(*form);
			boss.executeForm(*form);
			
			delete form;
		}
	}
	catch (const std::exception& e) 
	{
		std::cerr << R << "Exception: " << O << e.what() << RST << std::endl;
	}
	std::cout << std::endl;
}

void test8_BorderlineGrades()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 9: Borderline Grades             ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try 
	{
		Intern intern;
		
		// Presidential Pardon: sign 25, exec 5
		Bureaucrat signer("Signer", 25);
		Bureaucrat executor("Executor", 5);
		
		AForm* form = intern.makeForm("presidential pardon", "Criminal");
		std::cout << *form << std::endl;
		
		// Should succeed
		signer.signForm(*form);
		
		// Should succeed
		executor.executeForm(*form);
		
		delete form;
	}
	catch (const std::exception& e) 
	{
		std::cerr << R << "Exception: " << O << e.what() << RST << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	std::srand(std::time(NULL)); 
	
	test1_ValidFormCreation();
	test2_AllThreeForms();
	test3_InvalidFormName();
	test4_CaseSensitivityCheck();
	test5_GradeTooLowToSign();
	test6_GradeTooLowToExecute();
	test6_ExecuteUnsignedForm();
	test7_RobotomyRandomness();
	test8_BorderlineGrades();
	
	return (0);
}