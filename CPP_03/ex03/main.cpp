/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:28:27 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/13 17:53:55 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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
		bacon.beRepaired(5);
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
		scav.guardGate();
		scav.guardGate();
	}
		
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 3: Basic FragTrap        ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		FragTrap frag("Fraggy");
		FragTrap bacon("Bacon");
		
		frag.attack("Bacon");
		bacon.takeDamage(frag.getAD());
		bacon.beRepaired(15);
		frag.highFivesGuys();
		frag.highFivesGuys();
	}
		
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 4: Compare All Types     ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		ClapTrap clap("Clappy");
		ScavTrap scav("Scavy");
		FragTrap frag("Fraggy");
		
		std::cout << "\n" << BOLD_M << "Stats Comparison:" << RST << std::endl;
		displayStats("ClapTrap", clap);
		displayStats("ScavTrap", scav);
		displayStats("FragTrap", frag);

		std::cout << "\n" << BOLD_M << "Attack Comparison:" << RST << std::endl;
		clap.attack("Enemy");
		scav.attack("Enemy");
		frag.attack("Enemy");

		std::cout << "\n" << BOLD_M << "Special Abilities:" << RST << std::endl;
		scav.guardGate();
		frag.highFivesGuys();
	}
		
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 5: Energy Depletion      ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		FragTrap frag("Tired");
		
		std::cout << "\n" << BOLD_M << "Depleting energy..." << RST << std::endl;
		frag.setSP(3);
		while (frag.getSP() > 0)
			frag.attack("Enemy");
		
		std::cout << "\n" << BOLD_M << "Trying actions with no energy:" << RST << std::endl;
		frag.attack("Enemy");
		frag.beRepaired(5);
		frag.highFivesGuys();
	}
		
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 6: Death Scenarios       ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		FragTrap frag("Doomed");
		
		std::cout << "\n" << BOLD_M << "Taking lethal damage..." << RST << std::endl;
		frag.takeDamage(200);
		
		std::cout << "\n" << BOLD_M << "Trying actions while dead:" << RST << std::endl;
		frag.attack("Enemy");
		frag.beRepaired(5);
		frag.takeDamage(5);
		frag.highFivesGuys();
	}
		
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 7: Copy Operations       ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		std::cout << BOLD_M << "Creating original FragTrap:" << RST << std::endl;
		FragTrap original("Original");
		original.attack("Enemy");
		
		std::cout << "\n" << BOLD_M << "Copy constructor:" << RST << std::endl;
		FragTrap copy(original);
		copy.attack("Enemy");
		
		std::cout << "\n" << BOLD_M << "Copy assignment:" << RST << std::endl;
		FragTrap assigned("Assigned");
		assigned = original;
		assigned.attack("Enemy");
	}

	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 8: Copy Operations       ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		DiamondTrap D("ola");

		D.whoAmI();
	}

	return (0);
}
