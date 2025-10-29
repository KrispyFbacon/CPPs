/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:28:27 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/29 12:38:08 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		
		bob.attack();
		club.setType("Nuke");
		bob.attack();
	}
	std::cout << std::endl;
	{
		Weapon funny = Weapon("Hydrogen Bomb");
		HumanB bacon("Bacon");
		
		bacon.attack();
		bacon.setWeapon(funny);
		bacon.attack();
		funny.setType("Coughing Baby");
		bacon.attack();
	}
	return 0;
}