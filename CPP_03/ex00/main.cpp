/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:28:27 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/11 17:48:05 by frbranda         ###   ########.fr       */
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
		
		clap.attack("Target1");
		clap.takeDamage(3);
		clap.beRepaired(5);
	}
		
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 2: Energy depletion      ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		ClapTrap clap("Tired");
		
		// Use all 10 energy points
		for (int i = 0; i < 10; i++)
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
		ClapTrap original("Original");
		original.attack("Enemy");
		
		ClapTrap copy(original);  // Copy constructor
		copy.attack("Enemy");
		
		ClapTrap assigned("Assigned");
		assigned = original;  // Copy assignment
		assigned.attack("Enemy");
	}
		
	return 0;
}
