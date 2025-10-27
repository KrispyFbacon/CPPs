/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:28:27 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/27 17:20:01 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << BOLD_W << "Stack Zombie" 
			  << RST << std::endl;
	Zombie z("Foo");
	z.announce();
	
	std::cout << BOLD_W << "\nHeap Zombie (in main)"
			  << RST << std::endl;
	Zombie* z2 = new Zombie("Bacon");
	z2->announce();
	
	std::cout << BOLD_W << "\nHeap Zombie (calling newZombie)" 
			  << RST << std::endl;
	Zombie* z3 = newZombie("Bob");
	z3->announce();
	delete(z3);

	std::cout << BOLD_W << "\nrandomChump called"
			  << RST << std::endl;
	randomChump("Random");
	delete (z2);
	
	std::cout << BOLD_W << "\nAutomatically destroying Stack Zombies"
			  << RST << std::endl;
	return (0);
}