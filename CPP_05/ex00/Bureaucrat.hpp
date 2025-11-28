/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/28 18:39:10 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include "Color.hpp"

/* Class and identifier colors */
#define CLASS_COLOR	BOLD_Y
#define NAME_COLOR	RGB_BOLD(100, 150, 250)
#define NUM_COLOR	RGB_BOLD(255, 165, 0)

class Bureaucrat
{
	private:
		const static int _highestGrade = 1;
		const static int _lowestGrade = 150;
	
		const std::string _name;
		int _grade;
		
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();
		
		Bureaucrat& operator=(const Bureaucrat& other);

		//getters
		const std::string& getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{ 
					return "Grade too high!";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{ 
					return "Grade too low!";
				}
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);



#endif