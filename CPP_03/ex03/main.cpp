/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:28:27 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/14 11:49:24 by frbranda         ###   ########.fr       */
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
	std::cout << BOLD_C << "║  Test 4: Basic DiamondTrap     ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		DiamondTrap diamond("Diamondy");
		DiamondTrap target("Target");
		
		std::cout << "\n" << BOLD_M << "Actions:" << RST << std::endl;
		diamond.attack("Target");
		target.takeDamage(diamond.getAD());
		target.beRepaired(20);
		
		std::cout << "\n" << BOLD_M << "Special Abilities:" << RST << std::endl;
		diamond.whoAmI();
		diamond.guardGate();
		diamond.highFivesGuys();
		
		std::cout << std::endl;
	}
		
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 5: Compare All Types     ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		ClapTrap clap("Clappy");
		ScavTrap scav("Scavy");
		FragTrap frag("Fraggy");
		DiamondTrap diamond("Diamondy");
		
		std::cout << "\n" << BOLD_M << "Stats Comparison:" << RST << std::endl;
		displayStats("ClapTrap   ", clap);
		displayStats("ScavTrap   ", scav);
		displayStats("FragTrap   ", frag);
		displayStats("DiamondTrap", diamond);
		
		std::cout << "\n" << BOLD_M << "Attack Comparison:" << RST << std::endl;
		clap.attack("Enemy");
		scav.attack("Enemy");
		frag.attack("Enemy");
		diamond.attack("Enemy");  // Uses ScavTrap's attack
		
		std::cout << "\n" << BOLD_M << "Special Abilities:" << RST << std::endl;
		scav.guardGate();
		frag.highFivesGuys();
		diamond.guardGate();
		diamond.highFivesGuys();
		diamond.whoAmI();

		std::cout << std::endl;
	}
		
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 6: DiamondTrap whoAmI    ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		DiamondTrap d1("Alice");
		DiamondTrap d2("Bob");
		DiamondTrap d3("Charlie");
		
		std::cout << std::endl;
		
		d1.whoAmI();
		d2.whoAmI();
		d3.whoAmI();
		
		std::cout << std::endl;
	}
		
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 7: Energy Depletion      ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		DiamondTrap diamond("Tired");
		
		std::cout << "\n" << BOLD_M << "Depleting energy..." << RST << std::endl;
		diamond.setSP(3);
		while (diamond.getSP() > 0)
			diamond.attack("Enemy");
		
		std::cout << "\n" << BOLD_M << "Trying actions with no energy:" << RST << std::endl;
		diamond.attack("Enemy");
		diamond.beRepaired(5);
		diamond.guardGate();
		diamond.highFivesGuys();
		diamond.whoAmI();

		std::cout << std::endl;
	}
		
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 8: Death Scenarios       ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		DiamondTrap diamond("Doomed");
		
		std::cout << "\n" << BOLD_M << "Taking lethal damage..." << RST << std::endl;
		diamond.takeDamage(200);
		
		std::cout << "\n" << BOLD_M << "Trying actions while dead:" << RST << std::endl;
		diamond.attack("Enemy");
		diamond.beRepaired(5);
		diamond.takeDamage(5);
		diamond.guardGate();
		diamond.highFivesGuys();
		diamond.whoAmI();

		std::cout << std::endl;
	}
		
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 9: Copy Operations       ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		std::cout << BOLD_M << "Creating original DiamondTrap:" << RST << std::endl;
		DiamondTrap original("Original");
		original.whoAmI();
		original.attack("Enemy");
		
		std::cout << "\n" << BOLD_M << "Copy constructor:" << RST << std::endl;
		DiamondTrap copy(original);
		copy.whoAmI();
		copy.attack("Enemy");
		
		std::cout << "\n" << BOLD_M << "Copy assignment:" << RST << std::endl;
		DiamondTrap assigned("Assigned");
		assigned = original;
		assigned.whoAmI();
		assigned.attack("Enemy");

		std::cout << std::endl;
	}

	return (0);
}
