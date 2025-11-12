/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:28:27 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/12 18:14:15 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << BOLD_C << "╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 1: Basic ClapTrap        ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		ClapTrap clap("Clappy");
		ClapTrap bacon("Bacon");

		clap.attack("Bacon");
		bacon.takeDamage(clap.getAD());
		bacon.beRepaired(0);
	}
	
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 2: Basic ScavTrap        ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		ScavTrap scav("Scavy");
		ScavTrap bacon("Bacon");

		scav.attack("Bacon");
		bacon.takeDamage(scav.getAD());
		bacon.beRepaired(10);
		bacon.guardGate();
		bacon.guardGate();
	}
	
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 3: Energy depletion      ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		ScavTrap scav("Tired");
		
		scav.setSP(5);
		while (scav.getSP() > 0)
			scav.attack("Enemy");
		
		scav.attack("Enemy");
		scav.beRepaired(5);
		scav.guardGate();
	}
		
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 4: Death                 ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		ScavTrap scav("Doomed");
		
		scav.takeDamage(200);
		scav.attack("Enemy");
		scav.beRepaired(5);
		scav.takeDamage(5);
		scav.guardGate();
	}
		
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 5: Copy functionality    ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		ScavTrap original("Original");
		original.attack("Enemy");
		
		ScavTrap copy(original);
		copy.attack("Enemy");
		
		ScavTrap assigned("Assigned");
		assigned = original;
		assigned.attack("Enemy");
	}
	
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 6:                       ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		FragTrap frag("Faggy");
		FragTrap bacon("Bacon");
		
		frag.attack("Bacon");
		bacon.takeDamage(frag.getAD());
		bacon.beRepaired(10);
		bacon.highFivesGuys();
	}
	
	return 0;
}
