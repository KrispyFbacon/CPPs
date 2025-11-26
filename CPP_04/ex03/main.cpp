/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:28:27 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/26 18:14:11 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	// std::cout << BOLD_C << "╔════════════════════════════════╗" << RST << std::endl;
	// std::cout << BOLD_C << "║  Test 1: Character Ice/Cure    ║" << RST << std::endl;
	// std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	// {
	// 	ICharacter* me = new Character("me");
	// 	ICharacter* target = new Character("target");
	// 	AMateria* ice = new Ice();
	// 	AMateria* cure = new Cure();
		
	// 	AMateria* iceClone = ice->clone();
	// 	AMateria* cureClone = cure->clone();

	// 	std::cout << NAME_COLOR << "\nice:       " << RST << ice->getType() << std::endl;
	// 	std::cout << NAME_COLOR << "iceClone:  " << RST << iceClone->getColoredType() << std::endl;
	// 	std::cout << NAME_COLOR << "cure:      " << RST << cure->getType() << std::endl;
	// 	std::cout << NAME_COLOR << "cureClone: " << RST << cureClone->getColoredType() << "\n" << std::endl;

	// 	ice->use(*target);
	// 	iceClone->use(*target);
	// 	cure->use(*target);
	// 	cureClone->use(*target);

	// 	std::cout << std::endl;

	// 	ice->AMateria::use(*target);
	// 	AMateria* mate = ice->AMateria::clone();
	// 	if (mate)
	// 		mate->use(*target);

	// 	std::cout << std::endl;
		
	// 	me->checkInventory();
		
	// 	me->equip(ice);
	// 	me->equip(cure);
	// 	me->equip(iceClone);
	// 	me->equip(cureClone);

	// 	me->checkInventory();

	// 	std::cout << std::endl;

	// 	me->use(4, *target);

	// 	delete mate;
	// 	delete target;
	// }
	// std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	// std::cout << BOLD_C << "║  Test 2: MateriaSource         ║" << RST << std::endl;
	// std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	// {
	// 	IMateriaSource* src = new MateriaSource();
		
	// 	src->learnMateria(new Ice());
	// 	AMateria* tmp;
	// 	tmp = src->createMateria("cure");
	// 	src->learnMateria(new Cure());

	// 	ICharacter* me = new Character("me");

	// 	tmp = src->createMateria("ice");
	// 	me->equip(tmp);
	// 	tmp = src->createMateria("cure");
	// 	me->equip(tmp);

	// 	me->checkInventory();

	// 	ICharacter* bacon = new Character("bacon");
	
	// 	me->use(0, *bacon);
	// 	me->use(1, *bacon);
	// 	me->use(3, *bacon);
	// 	me->use(4, *bacon);

	// 	bacon->checkInventory();
	
	// 	delete bacon;
	// 	delete me;
	// 	delete src;
	//}
	
	// Test 1: Basic Functionality (Your existing test - keep it)
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
		
		ice->use(*target);
		iceClone->use(*target);
		cure->use(*target);
		cureClone->use(*target);
		
		me->equip(ice);
		me->equip(cure);
		me->equip(iceClone);
		me->equip(cureClone);
		me->checkInventory();
		
		me->use(0, *target);
		me->use(4, *target); // Out of bounds
		
		delete target;
		delete me; // Should delete all equipped materias
	}

	// Test 2: MateriaSource (Your existing test - keep it)
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 2: MateriaSource         ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		ICharacter* me = new Character("me");
		AMateria* tmp;
		
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		
		me->checkInventory();
		
		ICharacter* target = new Character("target");
		me->use(0, *target);
		me->use(1, *target);
		
		delete target;
		delete me;
		delete src;
	}

	// Test 3: CRITICAL - Unequip and Ground Management
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 3: Unequip & Ground      ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		ICharacter* me = new Character("me");
		AMateria* ice = new Ice();
		AMateria* cure = new Cure();
		
		me->equip(ice);
		me->equip(cure);
		me->checkInventory();
		
		std::cout << "\nUnequipping slot 0..." << std::endl;
		me->unequip(0); // Ice is now on "ground"
		me->checkInventory();
		
		std::cout << "\nUnequipping slot 1..." << std::endl;
		me->unequip(1); // Cure is now on "ground"
		me->checkInventory();
		
		// IMPORTANT: You must manage these yourself!
		// The character no longer owns them
		delete ice;   // Clean up "ground" materias
		delete cure;
		
		delete me;
	}

	// Test 4: Character Deep Copy
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 4: Character Deep Copy   ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		Character* hero = new Character("hero");
		hero->equip(new Ice());
		hero->equip(new Cure());
		
		std::cout << "\nOriginal hero:" << std::endl;
		hero->checkInventory();
		
		// Test copy constructor
		Character* heroCopy = new Character(*hero);
		std::cout << "\nCopied hero:" << std::endl;
		heroCopy->checkInventory();
		
		// Test that they're independent (deep copy)
		hero->unequip(0);
		std::cout << "\nAfter unequip from original:" << std::endl;
		std::cout << "Original:" << std::endl;
		hero->checkInventory();
		std::cout << "Copy (should be unchanged):" << std::endl;
		heroCopy->checkInventory();
		
		delete hero;
		delete heroCopy; // Should not crash (proves deep copy worked)
	}

	// Test 5: Character Assignment Operator
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 5: Character Assignment  ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		Character warrior("warrior");
		warrior.equip(new Ice());
		warrior.equip(new Cure());
		
		Character mage("mage");
		mage.equip(new Ice());
		
		std::cout << "\nBefore assignment:" << std::endl;
		warrior.checkInventory();
		mage.checkInventory();
		
		mage = warrior; // Assignment operator
		
		std::cout << "\nAfter assignment:" << std::endl;
		warrior.checkInventory();
		mage.checkInventory();
		
		// Test self-assignment
		//mage = mage;
		std::cout << "\nAfter self-assignment:" << std::endl;
		mage.checkInventory();
	}

	// Test 6: Inventory Overflow
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 6: Inventory Overflow    ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		ICharacter* me = new Character("me");
		
		// Fill inventory
		me->equip(new Ice());
		me->equip(new Cure());
		me->equip(new Ice());
		me->equip(new Cure());
		
		// Try to add 5th item (should fail)
		AMateria* extra = new Ice();
		std::cout << "\nTrying to equip 5th materia..." << std::endl;
		me->equip(extra);
		
		// IMPORTANT: Since equip failed, we still own 'extra'
		delete extra; // Must clean it up ourselves!
		
		me->checkInventory();
		delete me;
	}

	// Test 7: MateriaSource Edge Cases
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 7: MateriaSource Edge    ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		
		// Learn until full
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		// Try to learn 5th (should fail)
		AMateria* extra = new Ice();
		std::cout << "\nTrying to learn 5th materia..." << std::endl;
		src->learnMateria(extra);
		delete extra; // Must clean up if learn failed
		
		// Try to create unknown type
		std::cout << "\nTrying to create 'fire' (not learned)..." << std::endl;
		AMateria* fire = src->createMateria("fire");
		if (!fire)
			std::cout << "Correctly returned NULL" << std::endl;
		
		delete src;
	}

	// Test 8: NULL Pointer Handling
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 8: NULL Handling         ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		ICharacter* me = new Character("me");
		IMateriaSource* src = new MateriaSource();
		
		std::cout << "\nEquipping NULL..." << std::endl;
		me->equip(NULL);
		
		std::cout << "\nLearning NULL..." << std::endl;
		src->learnMateria(NULL);
		
		std::cout << "\nUnequipping empty slot..." << std::endl;
		me->unequip(0);
		
		std::cout << "\nUsing empty slot..." << std::endl;
		ICharacter* target = new Character("target");
		me->use(0, *target);
		
		delete target;
		delete me;
		delete src;
	}

	return 0;
}
