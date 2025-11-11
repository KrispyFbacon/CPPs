/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/11 18:13:15 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include "Color.hpp"

#define CLASS_COLOR	BOLD_Y
#define NAME_COLOR	C
#define DMG_COLOR	RGB(220, 69, 0)
#define HEAL_COLOR	RGB(152, 251, 152)

class	ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_HP;
		unsigned int	_SP;
		unsigned int	_AD;
		
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& other);

		~ClapTrap();

		ClapTrap& operator=(const ClapTrap& other);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		const std::string& getName() const;
};


#endif