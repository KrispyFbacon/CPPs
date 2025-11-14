/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/14 18:07:32 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Color.hpp"

/* Class and identifier colors */
#define CLASS_COLOR	BOLD_Y
#define NAME_COLOR	RGB_BOLD(100, 150, 250)

class	Animal
{
	protected:
		std::string _type;
		
	public:
		Animal();
		Animal(const Animal& other);
		
		virtual ~Animal();
		
		Animal& operator=(const Animal& other);

		virtual void makeSound();

		const std::string& getType() const;
		void setType(const std::string& type);
		
};
#endif