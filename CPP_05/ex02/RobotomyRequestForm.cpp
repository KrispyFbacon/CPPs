/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:49:16 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/03 18:48:25 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("Unkown_RobotomyRequestForm", _signGrade, _execGrade),
		_target("Unknown") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
	: AForm("RobotomyRequestForm", _signGrade, _execGrade), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}


/* ========================== Overload Operators =========================== */

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	
	return (*this);
}


/* ================================ Getters ================================ */

const std::string& RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}


/* ================================ Execute ================================ */

void RobotomyRequestForm::_execute() const
{
	std::cout << "* BRRRRRRRRRRRRRRRRRRRR *" << std::endl;
	
	if (std::rand() % 2 == 0)
	{
		std::cout << TARGET_COLOR << this->getTarget()
				  << G << " has been robotomized successfully!"
				  << RST << std::endl;
	}
	else 
		std::cout << R << "Robotomy failed! :c" << RST << std::endl;
}

