/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:58:30 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/04 14:35:24 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern::~Intern() {}


/* ========================== Overload Operators =========================== */

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other) {}
	
	return (*this);
}


/* ========================== Private Form Makers ========================== */

AForm* Intern::_makePresidentialForm(const std::string& target) const
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::_makeRobotomyForm(const std::string& target) const
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::_makeShrubberyForm(const std::string& target) const
{
	return (new ShrubberyCreationForm(target));
}


/* ============================== Make Form ================================ */

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	std::string names[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
		};
	
	AForm* (Intern::*creators[3])(const std::string&) const = {
		&Intern::_makePresidentialForm,
		&Intern::_makePresidentialForm,
		&Intern::_makePresidentialForm
		};

	for (int i = 0; i < 3; ++i)
	{
		if (names[i] == formName)
		{
			std::cout << G << "Intern creates " << FORM_COLOR << names[i]
					  << RST << std::endl;
			return ((this->*creators[i])(target));
		}
	}

	throw (FormNotFoundException());
}


/* ============================== Exceptions =============================== */

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Form Not Found";
}