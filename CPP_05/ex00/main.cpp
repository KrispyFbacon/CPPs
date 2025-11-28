/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:05:40 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/28 18:59:40 by frbranda         ###   ########.fr       */
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
		std::cout << "incrementGrade failed: " << R << e.what() << RST << std::endl;
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
		std::cout << "decrementGrade failed: " << R << e.what() << RST << std::endl;
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
	
	return 0;
}

