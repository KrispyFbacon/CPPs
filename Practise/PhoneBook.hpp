/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:54:50 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/16 11:23:12 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "color.hpp"

class	Car
{
	private:
		std::string	_brand;
		std::string	_model;
		int			_year;
	public:
		Car();
		Car(std::string brand, std::string model, int year);

		int	speed(int speed);

		void		carSet(std::string brand, std::string model, int year);
		void		brandSet(std::string brand);
		std::string	brandGet() const;
};

//class	PhoneBook
// {
// 	private:
// 		std::string	_brand;
// 		std::string	_model;
// 		int			_year;
// 	public:
// 		PhoneBook(std::string brand, std::string model, int year);
// 		int		speed(int MaxSpeed);
// 		void	displayCar();
		
// 		void		setModel(std::string model);
// 		std::string	getModel() const;
// };
