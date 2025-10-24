/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:56:15 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/24 12:12:27 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include "Color.hpp" // my color lib

class	Contact
{
	private:
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_NickName;
		std::string	_PhoneNumber;
		std::string	_DarkestSecret;
	public:
		Contact();
		~Contact();

		//Setters
		void	setFirstName(const std::string FirstName);
		void	setLastName(const std::string LastName);
		void	setNickName(const std::string NickName);
		void	setPhoneNumber(const std::string PhoneNumber);
		void	setDarkestSecret(const std::string DarkestSecret);

		//Getters
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;
};

#endif