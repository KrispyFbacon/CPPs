/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:05:40 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/05 11:55:59 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	test1_validBueaucrat()
{
	try
	{
		Bureaucrat bacon("bacon", 1);
		Bureaucrat a("a", 150);

		std::cout << bacon << std::endl;
		std::cout << a << std::endl;
	}
	catch (std::exception& e )
	{
		std::cout << R << e.what() << RST << std::endl;
	}
	std::cout << std::endl;
}

void	test2_invalidTooHigh()
{
	try
	{
		Bureaucrat tooHigh("tooHigh", 0);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << R << e.what() << RST << std::endl;
	}
	std::cout << std::endl;
}

void	test3_invalidTooLow()
{
	try
	{
		Bureaucrat tooLow("tooLow", 151);
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << R << e.what() << RST << std::endl;
	}
	std::cout << std::endl;
}

void	test4_invalidIncrematation()
{
	try
	{
		Bureaucrat onTop("onTop", 2);
		
		onTop.incrementGrade();
		std::cout << onTop << std::endl;
		
		onTop.incrementGrade();
		std::cout << onTop << std::endl;
	}
	catch(std::exception& e )
	{
		std::cout << "IncrementGrade failed: " << R << e.what() << RST << std::endl;
	}
	std::cout << std::endl;
}

void	test5_invalidDecrematation()
{
	try
	{
		Bureaucrat atBottom("atBottom", 149);
		
		atBottom.decrementGrade();
		std::cout << atBottom << std::endl;

		atBottom.decrementGrade();
		std::cout << atBottom << std::endl;
	}
	catch (std::exception& e )
	{
		std::cout << "DecrementGrade failed: " << R << e.what() << RST << std::endl;
	}
	std::cout << std::endl;
}

void	test6_invalidSpecialCatch()
{
	try
	{
		Bureaucrat a("a", 42);
		std::cout << a << std::endl;

		Bureaucrat b("b", -10);
		std::cout << b << std::endl;

		Bureaucrat c("c", 100);
		std::cout << c << std::endl;
		
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << R << e.what() << RST << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << R << e.what() << RST << std::endl;
	}
	std::cout << std::endl;
}

void	test7_copyConstructorAndAssignment()
{
	try
	{
		Bureaucrat original("Alice", 42);
		std::cout << "Original: " << original << std::endl;

		Bureaucrat copyConstructed(original);
		std::cout << "Copy constructed: " << copyConstructed << std::endl;
		
		original.incrementGrade();
		std::cout << BOLD_M << "\nAfter incrementing original:" << RST << std::endl;
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy constructed: " << copyConstructed << std::endl;
		
		
		std::cout << BOLD_M << "\n--- Testing Copy Assignment ---" << RST << std::endl;
		
		Bureaucrat bob("Bob", 100);
		std::cout << "Bob before assignment: " << bob << std::endl;
		
		bob = original;
		std::cout << "Bob after assignment: " << bob << std::endl;
		
		original.decrementGrade();
		std::cout << BOLD_M << "\nAfter decrementing original:" << RST << std::endl;
		std::cout << "Original: " << original << std::endl;
		std::cout << "Bob: " << bob << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << R << e.what() << RST << std::endl;
	}
	std::cout << std::endl;
}

int main ()
{
	{
		test1_validBueaucrat();
	}
	{
		test2_invalidTooHigh();
	}
	{
		test3_invalidTooLow();
	}
	{
		test4_invalidIncrematation();
	}
	{
		test5_invalidDecrematation();
	}
	{
		test6_invalidSpecialCatch();
	}
	{
		test7_copyConstructorAndAssignment();
	}
	return 0;
}

