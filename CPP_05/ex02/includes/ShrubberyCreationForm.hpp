/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:23:17 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/03 14:56:31 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Utils.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	
		const static int _signGrade = 145;
		const static int _execGrade = 137;

		void _execute() const;
		
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		const std::string& getTarget() const;
};


#endif