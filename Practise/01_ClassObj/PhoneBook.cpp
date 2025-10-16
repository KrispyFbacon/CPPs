/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:37:10 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/16 11:23:08 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Car::Car()
{
	std::cout << G << "New car constructed" << RST << std::endl;
}

Car::Car(std::string brand, std::string model, int year)
{
	std::cout << G << "New car constructed with: " << RST << std::endl;
	this->_brand = brand;
	std::cout << BOLD_C << "Brand: " << this->_brand << RST << std::endl;
	this->_model = model;
	std::cout << BOLD_C << "Model: " << this->_model << RST << std::endl;
	this->_year = year;
	std::cout << BOLD_C << "Year: " << this->_year << RST << std::endl;
}

int	Car::speed(int speed)
{
	return (speed);
}

void	Car::carSet(std::string brand, std::string model, int year)
{
	std::cout << BOLD_Y << "Changing whole car:" << RST << std::endl;
	this->_brand = brand;
	this->_model = model;
	this->_year = year;
	std::cout << BOLD_Y << "Brand: " << this->_brand << RST << std::endl;
	std::cout << BOLD_Y << "Model: " << this->_model << RST << std::endl;
	std::cout << BOLD_Y << "Year: " << this->_year << RST << std::endl;
}

void	Car::brandSet(std::string brand)
{
	std::cout << BOLD_Y << "Brand change from: " << BOLD_C << this->_brand;
	std::cout << BOLD_Y << " to: " << BOLD_C << brand << RST << std::endl;
	this->_brand = brand;
}

std::string	Car::brandGet() const
{
	return this->_brand;
}

int	main (void)
{
	Car car1;
	Car car2("BMW", "X5", 1999);

	car1.carSet("Mini", "Y9", 2000);
	
	std::cout << BOLD_W << "Car: " << BOLD_C << car1.brandGet();
	std::cout << BOLD_W << " is going at: " << BOLD_C << car1.speed(100) << RST << std::endl;
	std::cout << BOLD_W << "Car: " << BOLD_C << car2.brandGet();
	std::cout << BOLD_W << " is going at: " << BOLD_C << car2.speed(200) << RST << std::endl;

	car2.brandSet("Ferrari");
	std::cout << BOLD_W << "Getting brand: " << BOLD_C << car1.brandGet() << RST << std::endl;
	return (0);
}

/**
 * ----------------------------------------------------------------------------
*/

// // constructer and "setter"
// PhoneBook::PhoneBook(std::string brand, std::string model, int year)
// {
// 	std::cout << "Hello World!" << std::endl;
// 	this->_brand = brand;
// 	std::cout << "Set brand to: " << this->_brand << std::endl;
// 	this->_model = model;
// 	this->_year = year;
// }

// int	PhoneBook::speed(int MaxSpeed)
// {
// 	return (MaxSpeed);
// }

// void	PhoneBook::displayCar()
// {
// 	std::cout << BOLD_R << "Display:" << RST << std::endl;
// 	std::cout << BOLD_C << "Brand: " << this->_brand << RST << std::endl;
// 	std::cout << BOLD_C << "Model: " << this->_model << RST << std::endl;
// 	std::cout << BOLD_C << "Year: " << this->_year << RST << std::endl;
// }

// // MODEL SETTER AND GETTER
// void	PhoneBook::setModel(std::string model)
// {
// 	this->_model = model;
// }

// std::string	PhoneBook::getModel() const
// {
// 	return this->_model;
// }

// int	main()
// {
// 	PhoneBook obj("BMW", "X5", 1999);
	
// 	obj.displayCar();
// 	std::cout << obj.speed(100) << std::endl;
// 	std::cout << BOLD_Y << "Model Before: " << obj.getModel() << RST << std::endl;
// 	obj.setModel("Y9");
// 	std::cout << BOLD_Y << "Model After: " << obj.getModel() << RST << std::endl;
// 	return 0;
// }