/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/04 14:31:08 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTER_HPP
# define INTER_HPP

#include "Utils.hpp"

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		AForm* _makePresidentialForm(const std::string& target) const;
		AForm* _makeRobotomyForm(const std::string& target) const;
		AForm* _makeShrubberyForm(const std::string& target) const;
		
	public:
		Intern();
		Intern(const Intern& other);
		~Intern();
		
		Intern& operator=(const Intern& other);

		// Getters
		const std::string& getName() const;
		int getGrade() const;

		AForm* makeForm(const std::string& formName, const std::string& target) const;

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};


#endif