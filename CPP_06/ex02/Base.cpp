/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:29:38 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/18 16:51:05 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {};

Base* generate()
{
	switch (std::rand() % 3)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << A_COLOR << "A Class" << RST << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << B_COLOR << "B Class" << RST << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << C_COLOR << "C Class" << RST << std::endl;
	else
		std::cerr << BOLD_R << "Cannot identify Class" << RST << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)(dynamic_cast<A&>(p));
		std::cout << A_COLOR << "A Class" << RST << std::endl;
		return;
	}
	catch (...) {}
	
	try
	{
		(void)(dynamic_cast<B&>(p));
		std::cout << B_COLOR << "B Class" << RST << std::endl;
		return;
	}
	catch (...) {}
	
	try
	{
		(void)(dynamic_cast<C&>(p));
		std::cout << C_COLOR << "C Class" << RST << std::endl;
		return;
	}
	catch (...) {}
	
	std::cerr << BOLD_R << "Cannot identify Class" << RST << std::endl;
}