/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/02 18:55:18 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Utils.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		const int _signGrade;
		const int _execGrade;
		bool _isSigned;
	
		const static int _highestGrade = 1;
		const static int _lowestGrade = 150;
		
	public:
		Form();
		Form(const std::string& name, int signGrade, int execGrade);
		Form(const Form& other);
		~Form();

		Form& operator=(const Form& other);

		// setters
		void beSigned(const Bureaucrat& bureaucrat);

		// getters
		const std::string& getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool getSignedStatus() const;
		
		// exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class FormAlreadySigned : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif