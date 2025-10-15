/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:37:10 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/15 18:00:42 by frbranda         ###   ########.fr       */
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
		void	displayCar();
		
		void		setModel(std::string model);
		std::string	getModel() const;
};

// constructer and "setter"
PhoneBook::PhoneBook(std::string brand, std::string model, int year)
{
	std::cout << "Hello World!" << std::endl;
	this->_brand = brand;
	std::cout << "Set brand to: " << this->_brand << std::endl;
	this->_model = model;
	this->_year = year;
}

int	PhoneBook::speed(int MaxSpeed)
{
	return (MaxSpeed);
}

void	PhoneBook::displayCar()
{
	std::cout << BOLD_R << "Display:" << RST << std::endl;
	std::cout << BOLD_C << "Brand: " << this->_brand << RST << std::endl;
	std::cout << BOLD_C << "Model: " << this->_model << RST << std::endl;
	std::cout << BOLD_C << "Year: " << this->_year << RST << std::endl;
}

// MODEL SETTER AND GETTER
void	PhoneBook::setModel(std::string model)
{
	this->_model = model;
}

std::string	PhoneBook::getModel() const
{
	return this->_model;
}

int	main()
{
	PhoneBook obj("BMW", "X5", 1999);
	
	obj.displayCar();
	std::cout << obj.speed(100) << std::endl;
	std::cout << BOLD_Y << "Model Before: " << obj.getModel() << RST << std::endl;
	obj.setModel("Y9");
	std::cout << BOLD_Y << "Model After: " << obj.getModel() << RST << std::endl;
	return 0;
}