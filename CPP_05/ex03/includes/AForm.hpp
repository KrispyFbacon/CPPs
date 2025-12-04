/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:23:06 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/03 18:24:57 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Utils.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		const int _signGrade;
		const int _execGrade;
		bool _isSigned;
	
		const static int _highestGrade = 1;
		const static int _lowestGrade = 150;

		virtual void _execute() const = 0;

	public:
		AForm();
		AForm(const std::string& name, int signGrade, int execGrade);
		AForm(const AForm& other);
		virtual ~AForm();

		// Overload Operators
		AForm& operator=(const AForm& other);

		// Sign/Exec Handler
		void beSigned(const Bureaucrat& bureaucrat);
		void executeForm(Bureaucrat const & executor);

		// Getters
		const std::string& getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool getSignedStatus() const;
		
		// Exceptions
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

		class FormAlreadySignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif