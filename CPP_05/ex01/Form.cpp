/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:13:54 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/02 16:08:00 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: _name("unknow"), _signGrade(150), _execGrade(150), _isSigned(false) {}

Form::Form(const std::string& name, int signGrade, int execGrade)
	: _name(name), _signGrade(signGrade), _execGrade(execGrade),
		_isSigned(false)
{
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw (GradeTooHighException());
	else if (this->_signGrade > 150 || this->_execGrade > 150)
		throw (GradeTooLowException());
}

Form::Form(const Form& other)
	: _name(other._name), _signGrade(other._signGrade),
		_execGrade(other._execGrade), _isSigned(other._isSigned)
{}

Form::~Form() {}

Form& Form::operator=(const Form& other)
{
	if (this != &other){}
	
	return (*this);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (_isSigned == true)
		throw (FormAlreadySigned());
	else if (bureaucrat.getGrade() > this->_signGrade)
		throw (GradeTooLowException());
	else if (bureaucrat.getGrade() > this->_execGrade)
		throw (GradeTooLowException());
	_isSigned = true;
}


/* -------------------------------- Getters -------------------------------- */

const std::string& Form::getName() const
{
	return this->_name;
}

const int& Form::getSignGrade() const
{
	return this->_signGrade;
}

const int& Form::getExecGrade() const
{
	return this->_execGrade;
}

bool Form::getSignedStatus() const
{
	return this->_isSigned;
}


/* ------------------------------ Exceptions ------------------------------- */

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char* Form::FormAlreadySigned::what() const throw()
{
	return "Form already signed!";
}

/* -------------------------------- ostream -------------------------------- */

std::ostream& operator<<(std::ostream& os, const Form& f)
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