/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/12 17:15:13 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include "Color.hpp"

/* Class and identifier colors */
#define CLASS_COLOR	BOLD_Y
#define NAME_COLOR	RGB_BOLD(100, 150, 250)

/* Action colors */
#define DMG_COLOR	RGB(220, 69, 0)
#define HEAL_COLOR	RGB(152, 251, 152)
#define NUM_COLOR	RGB_BOLD(255, 165, 0)

class	ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_HP;
		unsigned int	_SP;
		unsigned int	_AD;
		std::string		_type;
		
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& other);

		~ClapTrap();

		ClapTrap& operator=(const ClapTrap& other);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		// Setters
		void setSP(const unsigned int& SP);
		
		// Getters
		const unsigned int& getSP() const;
		const unsigned int& getAD() const;
};


#endif