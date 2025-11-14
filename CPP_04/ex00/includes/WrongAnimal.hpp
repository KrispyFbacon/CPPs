/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/14 17:17:25 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include "Color.hpp"

/* Class and identifier colors */
#define CLASS_COLOR	BOLD_Y
#define NAME_COLOR	RGB_BOLD(100, 150, 250)

class	WrongAnimal
{
	protected:
		std::string _type;
		
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		
		~WrongAnimal();
		
		WrongAnimal& operator=(const WrongAnimal& other);

		void makeSound();

		const std::string& getType() const;
		void setType(const std::string& type);
		
};
#endif