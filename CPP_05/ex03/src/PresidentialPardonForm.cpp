/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:49:16 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/04 13:22:18 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("PresidentialPardonForm", _signGrade, _execGrade),
		_target("Unknown") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
	: AForm("PresidentialPardonForm", _signGrade, _execGrade), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), _target(other._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}


/* ========================== Overload Operators =========================== */

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	
	return (*this);
}


/* ================================ Getters ================================ */

const std::string& PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}


/* ================================ Execute ================================ */

void PresidentialPardonForm::_execute() const
{
	std::cout << "I am here by declare that "
			  << TARGET_COLOR << this->getTarget()
			  << RST << " has been pardoned by our glorious Zaphod Beeblebrox"
			  << std::endl;
}

