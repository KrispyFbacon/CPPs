/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:28:27 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/13 13:46:31 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << BOLD_C << "╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 1: Basic ClapTrap        ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		ClapTrap scav("Clappy");
		ClapTrap bacon("Bacon");

		scav.attack("Bacon");
		bacon.takeDamage(scav.getAD());
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
	std::cout << BOLD_C << "║  Test 3: Compare All Types     ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		ClapTrap clap("Clappy");
		ScavTrap scav("Scavy");
		
		std::cout << "\n" << BOLD_M << "Stats Comparison:" << RST << std::endl;
		displayStats("ClapTrap", clap);
		displayStats("ScavTrap", scav);

		std::cout << "\n" << BOLD_M << "Attack Comparison:" << RST << std::endl;
		clap.attack("Enemy");
		scav.attack("Enemy");
		
		std::cout << "\n" << BOLD_M << "Special Abilities:" << RST << std::endl;
		scav.guardGate();
	}
	
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 4: Energy depletion      ║" << RST << std::endl;
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
	std::cout << BOLD_C << "║  Test 5: Death                 ║" << RST << std::endl;
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
	std::cout << BOLD_C << "║  Test 6: Copy functionality    ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		std::cout << BOLD_M << "Creating original FragTrap:" << RST << std::endl;
		ScavTrap original("Original");
		original.attack("Enemy");
		
		std::cout << "\n" << BOLD_M << "Copy constructor:" << RST << std::endl;
		ScavTrap copy(original);
		copy.attack("Enemy");
		
		std::cout << "\n" << BOLD_M << "Copy assignment:" << RST << std::endl;
		ScavTrap assigned("Assigned");
		assigned = original;
		assigned.attack("Enemy");

	}
	
	return 0;
}
