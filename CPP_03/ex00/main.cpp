/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:28:27 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/13 13:46:53 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << BOLD_C << "╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 1: Basic functionality   ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		ClapTrap clap("Clappy");
		ClapTrap bacon("Bacon");

		displayStats("ClapTrap", clap);
		
		clap.attack("Bacon");
		bacon.takeDamage(clap.getAD());
		bacon.beRepaired(0);
	}
		
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 2: Energy depletion      ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		ClapTrap clap("Tired");
		
		// Use all 10 -> 5 energy points
		clap.setSP(5);
		while (clap.getSP() > 0)
			clap.attack("Enemy");
		
		// Try to attack with no energy
		clap.attack("Enemy");
		clap.beRepaired(5);
	}
		
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 3: Death                 ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		ClapTrap clap("Doomed");
		
		clap.takeDamage(10);  // Kill it
		clap.attack("Enemy");  // Try to attack while dead
		clap.beRepaired(5);	// Try to repair while dead
		clap.takeDamage(5);	// Hit dead body
	}
		
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 4: Copy functionality    ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		std::cout << BOLD_M << "Creating original FragTrap:" << RST << std::endl;
		ClapTrap original("Original");
		original.attack("Enemy");
		
		std::cout << "\n" << BOLD_M << "Copy constructor:" << RST << std::endl;
		ClapTrap copy(original);  // Copy constructor
		copy.attack("Enemy");
		
		std::cout << "\n" << BOLD_M << "Copy assignment:" << RST << std::endl;
		ClapTrap assigned("Assigned");
		assigned = original;  // Copy assignment
		assigned.attack("Enemy");
	}
		
	return 0;
}
