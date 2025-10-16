/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Practise.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:56:53 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/16 14:17:24 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Practise.hpp"

// Base class
class Vehicle
{
	private:
		std::string _brand;
	public:
		Vehicle();
		void honk();
};

// Derived class
class Car
{
	private:
		std::string _model;
	public:
		Car();
};

/**
 * VEHICLE .CPP
 */

Vehicle::Vehicle()
{
	std::cout << G << "New Vehicle contructed "<< RST << std::endl;
}
 
 void	Vehicle::honk()
{
	std::cout << "Tuut, tuut! " << std::endl;
}

/**
 * CAR.CPP
 */

Car::Car()
{
	std::cout << B << "New Car contructed "<< RST << std::endl;
}

 
/**
 * MAIN
 */
int	main()
{
	Car	myCar;
	
	myCar.honk();
	std::cout << myCar.brand + " " + myCar.model << std::endl;
	return 0;
}