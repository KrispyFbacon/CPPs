/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:37:10 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/15 16:09:45 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

class	PhoneBook
{
	private:
		std::string	_brand;
		std::string	_model;
		int			_year;
	public:
		PhoneBook(std::string brand, std::string model, int year);
		int		speed(int MaxSpeed);
};

PhoneBook::PhoneBook(std::string brand, std::string model, int year)
{
	std::cout << "Hello World!" << std::endl;
	_brand = brand; // setter
	_model = model;
	_year = year;
}

/* TODO now missing getter to print out*/

int	PhoneBook::speed(int MaxSpeed)
{
	return (MaxSpeed);
}

int	main()
{
	PhoneBook obj("BMW", "X5", 1999);
	
	std::cout << obj.speed(100) << std::endl;
	return 0;
}