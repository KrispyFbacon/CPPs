/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:28:27 by frbranda          #+#    #+#             */
/*   Updated: 2026/02/19 18:15:58 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << BOLD_W << "\n==Stack Zombie==" << RST << std::endl;
	Zombie z("Foo");
	z.announce();
	
	std::cout << BOLD_W << "\n==Heap Zombie (in main)==" << RST << std::endl;
	Zombie* z2 = new Zombie("Bacon");
	z2->announce();
	
	std::cout << BOLD_W << "\n==Heap Zombie (calling newZombie)=="
			  << RST << std::endl;
	Zombie* z3 = newZombie("Bob");
	z3->announce();
	delete(z3);

	std::cout << BOLD_W << "\n==randomChump called==" << RST << std::endl;
	randomChump("Random");
	delete (z2);
	
	std::cout << BOLD_W << "\n==Automatically destroying Stack Zombies=="
			  << RST << std::endl;
	return (0);
}