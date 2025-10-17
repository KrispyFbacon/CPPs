/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:54:50 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/17 11:42:03 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Color.hpp" // my color lib
#include "Printer.hpp" // prints and errors
#include "Contact.hpp"

class	PhoneBook
{
	private:
		int		_i;
		Contact	contact[8];
	public:
		PhoneBook();

		void	add();
		void	search();
		
		std::string	getInput(const std::string &prompt);
		std::string formatField(const std::string &str);
};

#endif