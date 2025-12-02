/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:05:40 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/02 19:04:57 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

void	test1_validFormCreation()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 1: Valid Form Creation           ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try
	{
		Form f1("Food Form", 50, 25);
		Form f2("Tax fraud", 25, 5);

		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		
	}
	catch (const std::exception& e)
	{
		std::cout << O << e.what() << RST << std::endl;
	}
	std::cout << std::endl;
}

void test2_invalidFormTooHigh()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 2: Invalid Form (Too High)       ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try
	{
		Form f("Invalid", 0, 50);
	}
	catch (const std::exception& e)
	{
		std::cout << O << e.what() << RST << std::endl;
	}
	
	try
	{
		Form f("Invalid", 50, 0);
	}
	catch (const std::exception& e)
	{
		std::cout << O << e.what() << RST << std::endl;
	}
	std::cout << std::endl;
}

void test3_invalidFormTooLow()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 3: Invalid Form (Too Low)        ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try
	{
		Form f("Invalid", 151, 50);
	}
	catch (const std::exception& e)
	{
		std::cout << O << e.what() << RST << std::endl;
	}
	
	try
	{
		Form f("Invalid", 50, 200);
	}
	catch (const std::exception& e)
	{
		std::cout << O << e.what() << RST << std::endl;
	}
	std::cout << std::endl;
}

void test4_successfulSigning()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 4: Successful Form Signing       ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try
	{
		Bureaucrat bacon("Bacon", 25);
		Form form("Contract", 50, 25);
		
		std::cout << "\nBefore signing:" << std::endl;
		std::cout << form << std::endl;
		
		bacon.signForm(form);
		
		std::cout << "\nAfter signing:" << std::endl;
		std::cout << form << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << O << e.what() << RST << std::endl;
	}
	std::cout << std::endl;
}

void test5_bureaucratGradeTooLow()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 5: Bureaucrat Grade Too Low      ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try
	{
		Bureaucrat lowGrade("LowGrade", 100);
		Form importantForm("Top Secret", 50, 25);
		
		std::cout << lowGrade << std::endl;
		std::cout << importantForm << std::endl;
		
		lowGrade.signForm(importantForm);
		
		std::cout << importantForm << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << O << e.what() << RST << std::endl;
	}
	std::cout << std::endl;
}

void test6_signFormTwice()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 6: Sign Form Twice (Fail)        ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try
	{
		Bureaucrat bacon("Bacon", 1);
		Form form("Simple Form", 10, 5);
		
		bacon.signForm(form);
		bacon.signForm(form);
		
		std::cout << form << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << O << e.what() << RST << std::endl;
	}
	std::cout << std::endl;
}

void test7_edgeCaseGrade1()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 7: Edge Case (Grade 1)           ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try
	{
		Bureaucrat supreme("Supreme", 1);
		Form hardForm("Hardest Form", 1, 1);
		
		std::cout << supreme << std::endl;
		std::cout << hardForm << std::endl;
		
		supreme.signForm(hardForm);
		
		std::cout << hardForm << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << O << e.what() << RST << std::endl;
	}
	std::cout << std::endl;
}

void test8_edgeCaseGrade150()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 8: Edge Case (Grade 150)         ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		Form easyForm("Easy Form", 150, 150);
		
		std::cout << intern << std::endl;
		std::cout << easyForm << std::endl;
		
		intern.signForm(easyForm);
		
		std::cout << easyForm << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << O << e.what() << RST << std::endl;
	}
	std::cout << std::endl;
}

void test9_copyConstructor()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 9: Copy Constructor              ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try
	{
		Form original("Original", 50, 25);
		Bureaucrat signer("Signer", 30);
		
		signer.signForm(original);
		
		Form copy(original);
		
		std::cout << "\nOriginal:" << std::endl;
		std::cout << original << std::endl;
		std::cout << "\nCopy:" << std::endl;
		std::cout << copy << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << O << e.what() << RST << std::endl;
	}
	std::cout << std::endl;
}

void test10_multipleBureaucrats()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 10: Multiple Bureaucrats         ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try
	{
		Form form("Shared Form", 50, 25);
		Bureaucrat good("Good", 40);
		Bureaucrat bad("Bad", 60);
		
		std::cout << form << std::endl;
		
		bad.signForm(form);
		good.signForm(form);
		bad.signForm(form);
	}
	catch (const std::exception& e)
	{
		std::cout << O << e.what() << RST << std::endl;
	}
	std::cout << std::endl;
}

int main ()
{
	test1_validFormCreation();
	test2_invalidFormTooHigh();
	test3_invalidFormTooLow();
	test4_successfulSigning();
	test5_bureaucratGradeTooLow();
	test6_signFormTwice();
	test7_edgeCaseGrade1();
	test8_edgeCaseGrade150();
	test9_copyConstructor();
	test10_multipleBureaucrats();


	return 0;
}

