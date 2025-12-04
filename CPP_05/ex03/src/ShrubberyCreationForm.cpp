/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:49:16 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/04 13:22:29 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("ShrubberyCreationForm", _signGrade, _execGrade),
		_target("Unknown") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
	: AForm("ShrubberyCreationForm", _signGrade, _execGrade), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


/* ========================== Overload Operators =========================== */

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	
	return (*this);
}


/* ================================ Getters ================================ */

const std::string& ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}


/* ================================ Execute ================================ */

void ShrubberyCreationForm::_execute() const
{
	std::string filename = this->getTarget() + "_shrubbery";
	std::ofstream outFile(filename.c_str());

	if (!outFile.is_open())
		throw std::runtime_error("Failed to create file");

	outFile << "       ###\n";
	outFile << "      #o###\n";
	outFile << "    #####o###\n";
	outFile << "   #o#\\#|#/###\n";
	outFile << "    ###\\|/#o#\n";
	outFile << "     # }|{  #\n";
	outFile << "       }|{\n";
	outFile << "       }|{\n";

	outFile.close();

	std::cout << "Created " << TARGET_COLOR << filename 
			  << RST << " with ASCII trees" << std::endl;
}

