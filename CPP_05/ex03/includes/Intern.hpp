/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/04 17:14:42 by frbranda         ###   ########.fr       */
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
		typedef AForm* (Intern::*FormCreator)(const std::string&) const;

		struct FormInfo
		{
			std::string	name;
			FormCreator	creator;
		};

		static const FormInfo _forms[];
		static const int _numForms;

		AForm* _makePresidentialForm(const std::string& target) const;
		AForm* _makeRobotomyForm(const std::string& target) const;
		AForm* _makeShrubberyForm(const std::string& target) const;
		
	public:
		Intern();
		Intern(const Intern& other);
		~Intern();
		
		Intern& operator=(const Intern& other);

		AForm* makeForm(const std::string& formName, const std::string& target) const;

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};


#endif