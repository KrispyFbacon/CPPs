/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:28:27 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/26 13:50:06 by frbranda         ###   ########.fr       */
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
	std::cout << BOLD_C << "║  Test 1: Character Ice/Cure    ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		ICharacter* me = new Character("me");
		ICharacter* target = new Character("target");
		AMateria* ice = new Ice();
		AMateria* cure = new Cure();
		
		AMateria* iceClone = ice->clone();
		AMateria* cureClone = cure->clone();

		std::cout << NAME_COLOR << "\nice:       " << RST << ice->getType() << std::endl;
		std::cout << NAME_COLOR << "iceClone:  " << RST << iceClone->getColoredType() << std::endl;
		std::cout << NAME_COLOR << "cure:      " << RST << cure->getType() << std::endl;
		std::cout << NAME_COLOR << "cureClone: " << RST << cureClone->getColoredType() << "\n" << std::endl;

		ice->use(*target);
		iceClone->use(*target);
		cure->use(*target);
		cureClone->use(*target);

		std::cout << std::endl;

		ice->AMateria::use(*target);
		AMateria* mate = ice->AMateria::clone();
		if (mate)
			mate->use(*target);

		std::cout << std::endl;
		
		me->checkInventory();

		std::cout << std::endl;
		
		me->equip(ice);
		me->equip(cure);
		me->equip(iceClone);
		me->equip(cureClone);

		std::cout << std::endl;
		
		me->checkInventory();

		std::cout << std::endl;

		me->use(4, *target);

		delete mate;
		delete target;
	}
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 2: MateriaSource         ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{

	}

	// std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	// std::cout << BOLD_C << "║  Test 3: Given main            ║" << RST << std::endl;
	// std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	// {
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
