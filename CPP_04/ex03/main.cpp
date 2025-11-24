/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:28:27 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/24 17:52:14 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include "Character.hpp"

#define ARRAY_SIZE 8

int main()
{
	std::cout << BOLD_C << "╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 1: Materia Ice/Cure      ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		AMateria* ice = new Ice();
		AMateria* cure = new Cure();
		
		AMateria* iceClone = ice->clone();
		AMateria* cureClone = cure->clone();

		std::cout << NAME_COLOR << "\nIce:        " << RST << ice->getType() << std::endl;
		std::cout << NAME_COLOR << "Ice Clone:  " << RST << iceClone->getType() << std::endl;
		std::cout << NAME_COLOR << "Cure:       " << RST << cure->getType() << std::endl;
		std::cout << NAME_COLOR << "Cure Clone: " << RST << cureClone->getType() << "\n" << std::endl;

		ice->tempUse("target");
		iceClone->tempUse("target");
		cure->tempUse("target");
		cureClone->tempUse("target");

		std::cout << std::endl;

		ice->AMateria::tempUse("target");
		AMateria* mate = ice->AMateria::clone();
		mate->tempUse("target");
		

		std::cout << std::endl;

		delete ice;
		delete iceClone;
		delete cure;
		delete cureClone;
		
		// TODO invetory
		
		// AMateria* allMateria[] = {
		// 	new Ice(),
		// 	new Cure()
		// } ;
		
		// std::cout << "Animal[" << NUM_COLOR << i << RST << "]: " 
		// 			  << NAME_COLOR << animal[i]->getType() 
		// 			  << RST << std::endl;
		
	}
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 2: Character             ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		Character* player = new Character();
		
		player->checkInventory();
		
	}

	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	// ICharacter* me = new Character("me");
	
	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	
	// ICharacter* bob = new Character("bob");
	
	// me->use(0, *bob);
	// me->use(1, *bob);
	
	// delete bob;
	// delete me;
	// delete src;

	return 0;
}
