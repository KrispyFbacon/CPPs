/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/13 17:49:04 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define WHOAMI_COLOR RGB_BOLD(218, 165, 32)
//RGB_BOLD(186, 85, 211)
//RGB_BOLD(0, 206, 209) 

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;
		
		void _initDiamondStats();

	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& other);

		~DiamondTrap();

		DiamondTrap& operator=(const DiamondTrap& other);

		void attack(const std::string& target);
		void whoAmI();
};


#endif