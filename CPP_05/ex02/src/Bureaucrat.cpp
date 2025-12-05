/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:58:30 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/05 15:35:02 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(_lowestGrade) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
		: _name(name), _grade(grade)
{
	if (this->_grade < _highestGrade)
		throw (GradeTooHighException());
	else if (this->_grade > _lowestGrade)
		throw (GradeTooLowException());
	
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
		: _name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat() {}


/* ========================== Overload Operators =========================== */

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}


/* ================================ Getters ================================ */

const std::string& Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}


/* ========================== Increment/Decrement ========================== */

void Bureaucrat::incrementGrade()
{
	if (this->_grade <= _highestGrade)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade >= _lowestGrade)
		throw GradeTooLowException();
	this->_grade++;
}


/* ============================= Form Handler ============================== */

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << NAME_COLOR << this->_name << G << " signed "
				  << FORM_COLOR << form.getName() << RST << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << NAME_COLOR << this->_name << R << " couldn't sign "
				  << FORM_COLOR << form.getName() << R << " because "
				  << O << e.what() << RST << std::endl;
	}
}

void Bureaucrat::executeForm(AForm& form) const
{
	try
	{
		form.executeForm(*this);
		std::cout << NAME_COLOR << this->_name << G << " executed "
				  << FORM_COLOR << form.getName() << RST << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << NAME_COLOR << this->_name << R << " couldn't execute "
				  << FORM_COLOR << form.getName() << R << " because "
				  << O << e.what() << RST << std::endl;
	}
}


/* ============================== Exceptions =============================== */

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}


/* ================================ Ostream ================================ */

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << NAME_COLOR << b.getName() << RST ", "
		  << CLASS_COLOR << "bureaucrat" << RST " grade "
		  << NUM_COLOR << b.getGrade() << RST;
	
	return (os);
}