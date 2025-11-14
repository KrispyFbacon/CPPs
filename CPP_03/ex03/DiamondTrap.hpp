/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/14 13:10:11 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define WHOAMI_COLOR RGB_BOLD(220, 165, 30)

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

		using ScavTrap::attack;
		void whoAmI();
};


#endif