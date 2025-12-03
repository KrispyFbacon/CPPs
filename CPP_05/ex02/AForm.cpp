/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:49:16 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/03 18:37:57 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	: _name("unknow"), _signGrade(_lowestGrade), _execGrade(_lowestGrade), _isSigned(false) {}

AForm::AForm(const std::string& name, int signGrade, int execGrade)
	: _name(name), _signGrade(signGrade), _execGrade(execGrade),
		_isSigned(false)
{
	if (this->_signGrade < _highestGrade || this->_execGrade < _highestGrade)
		throw (GradeTooHighException());
	else if (this->_signGrade > _lowestGrade || this->_execGrade > _lowestGrade)
		throw (GradeTooLowException());
}

AForm::AForm(const AForm& other)
	: _name(other._name), _signGrade(other._signGrade),
		_execGrade(other._execGrade), _isSigned(other._isSigned)
{}

AForm::~AForm() {}


/* ========================== Overload Operators =========================== */

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other){}
	
	return (*this);
}


/* =========================== Sign Handler =========================== */

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (_isSigned == true)
		throw (FormAlreadySignedException());
	else if (bureaucrat.getGrade() > this->_signGrade)
		throw (GradeTooLowException());
	_isSigned = true;
}

void AForm::executeForm(Bureaucrat const & executor)
{
	if (_isSigned == false)
		throw (FormNotSignedException());
	else if (executor.getGrade() > this->_signGrade)
		throw (GradeTooLowException());
	std::cout << NAME_COLOR << executor.getName() << RST << " ";
	this->_execute();
}

/* ================================ Getters ================================ */

const std::string& AForm::getName() const
{
	return this->_name;
}

int AForm::getSignGrade() const
{
	return this->_signGrade;
}

int AForm::getExecGrade() const
{
	return this->_execGrade;
}

bool AForm::getSignedStatus() const
{
	return this->_isSigned;
}


/* ============================== Exceptions =============================== */

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char* AForm::FormAlreadySignedException::what() const throw()
{
	return "Form already signed!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed!");
}


/* ================================ Ostream ================================ */

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "┌─────────────────────────────────────────┐\n"
	<< "│ " << CLASS_COLOR << "Form" << RST << "\n"
	<< "├─────────────────────────────────────────┤\n"
	<< "│ " << BOLD_M << "Name:       " 
	<< NAME_COLOR << f.getName() << RST << "\n"
	<< "│ " << BOLD_M << "Sign Grade: " 
	<< NUM_COLOR << f.getSignGrade() << RST << "\n"
	<< "│ " << BOLD_M << "Exec Grade: " 
	<< NUM_COLOR << f.getExecGrade() << RST << "\n"
	<< "│ " << BOLD_M << "Signed:     " 
	<< (f.getSignedStatus() ? G "Yes" : R "No") 
	<< RST << "\n"
	<< "└─────────────────────────────────────────┘";
	
	return (os);
}