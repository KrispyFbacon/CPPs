/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:54:50 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/24 12:54:32 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Color.hpp" // my color lib
#include "Printer.hpp" // prints and errors
#include "Contact.hpp"

#define	MAX_CONTACTS 8

class	PhoneBook
{
	private:
		int		_index;
		Contact	contact[MAX_CONTACTS];

		std::string	getInput(const std::string &prompt);
		std::string formatField(const std::string &str);
		bool isValidIndex(const std::string &index) const;
		void displayContact(const int &index) const;
		
	public:
		PhoneBook();
		~PhoneBook();

		void	add();
		void	search();
};

#endif