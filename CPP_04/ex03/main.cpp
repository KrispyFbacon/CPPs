/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:05:40 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/27 17:35:34 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void test1_CharacterIceCure()
{
	std::cout << BOLD_C << "╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 1: Character Ice/Cure    ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	
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
	
	me->checkInventory();
	me->equip(ice);
	me->equip(cure);
	me->equip(iceClone);
	me->equip(cureClone);
	me->checkInventory();
	
	me->equip(cure); // Try to equip already equipped materia

	me->use(0, *target);
	me->use(INVENTORY_SIZE, *target); // Invalid index
	
	delete target;
	delete me; // Should delete all equipped materias
}

void test2_MateriaSource()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 2: MateriaSource         ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	AMateria* tmp;
	
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->equip(tmp); // Try to equip same materia twice
	
	me->checkInventory();
	
	ICharacter* target = new Character("target");
	me->use(0, *target);
	me->use(1, *target);
	
	delete target;
	delete me;
	delete src;
}

void test3_UnequipAndGround()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 3: Unequip & Ground      ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	
	ICharacter* me = new Character("me");
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	
	me->equip(ice);
	me->equip(cure);
	me->checkInventory();
	
	std::cout << BOLD_C << "\n Unequipping slot 0..." << RST << std::endl;
	me->unequip(0); // Ice is now on "ground"
	me->checkInventory();
	
	std::cout << BOLD_C << "\n Unequipping slot 1..." << RST << std::endl;
	me->unequip(1); // Cure is now on "ground"
	me->checkInventory();
	
	std::cout << BOLD_C << "\n Trying to unequip already empty slot..." << RST << std::endl;
	me->unequip(0); // Should fail gracefully
	
	delete me;
	// Floor will be cleaned when last Character is destroyed
}

void test4_CharacterDeepCopy()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 4: Character Deep Copy   ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	
	Character* hero = new Character("hero");
	hero->equip(new Ice());
	hero->equip(new Cure());
	
	std::cout << BOLD_C << "\n Original hero:" << RST << std::endl;
	hero->checkInventory();
	
	// Test copy constructor
	Character* heroCopy = new Character(*hero);
	std::cout << BOLD_C << "\n Copied hero:" << RST << std::endl;
	heroCopy->checkInventory();
	
	// Test that they're independent (deep copy)
	hero->unequip(0);
	std::cout << BOLD_C << "\n After unequip from original:" << RST << std::endl;
	std::cout << BOLD_C << "\nOriginal:" << RST << std::endl;
	hero->checkInventory();
	std::cout << BOLD_C << "Copy (should be unchanged):" << RST << std::endl;
	heroCopy->checkInventory();
	
	delete hero;
	delete heroCopy; // Should not crash (proves deep copy worked)
}

void test5_CharacterAssignment()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 5: Character Assignment  ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	
	Character warrior("warrior");
	warrior.equip(new Ice());
	warrior.equip(new Cure());
	
	Character mage("mage");
	mage.equip(new Cure());
	
	std::cout << BOLD_C << "\n Before assignment:" << std::endl;
	warrior.checkInventory();
	mage.checkInventory();
	
	mage = warrior; // Assignment operator
	
	std::cout << BOLD_C << "\n After assignment:" << std::endl;
	warrior.checkInventory();
	mage.checkInventory();
}

void test6_InventoryOverflow()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 6: Inventory Overflow    ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	
	ICharacter* me = new Character("me");
	
	// Fill inventory
	me->equip(new Ice());
	me->equip(new Cure());
	me->equip(new Ice());
	me->equip(new Cure());
	
	// Try to add 5th item (should fail)
	AMateria* extra = new Ice();
	std::cout << BOLD_C << "\n Trying to equip 5th materia..." << RST << std::endl;
	me->equip(extra);
	
	delete extra; // Must clean it up ourselves!
	
	me->checkInventory();
	delete me;
}

void test7_MateriaSourceEdgeCases()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 7: MateriaSource Edge    ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	
	// Learn until full
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	// Try to learn 5th (should fail)
	AMateria* extra = new Ice();
	std::cout << BOLD_C << "\n Trying to learn 5th materia..." << RST << std::endl;
	src->learnMateria(extra);
	delete extra; // Must clean up if learn failed
	
	// Try to create unknown type
	std::cout << BOLD_C << "\n Trying to create 'fire' (not learned)..." << RST << std::endl;
	AMateria* fire = src->createMateria("fire");
	if (!fire)
		std::cout << "Correctly returned NULL" << std::endl;
	
	std::cout << std::endl;

	delete src;
}

void test8_NullPointerHandling()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 8: NULL Handling         ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	
	ICharacter* me = new Character("me");
	IMateriaSource* src = new MateriaSource();
	
	std::cout << BOLD_C << "\n Equipping NULL..." << RST << std::endl;
	me->equip(NULL);
	
	std::cout << BOLD_C << "\n Learning NULL..." << RST << std::endl;
	src->learnMateria(NULL);
	
	std::cout << BOLD_C << "\n Unequipping empty slot..." << RST << std::endl;
	me->unequip(0);
	
	std::cout << BOLD_C << "\n Using empty slot..." << RST << std::endl;
	ICharacter* target = new Character("target");
	me->use(0, *target);

	std::cout << std::endl;
	
	delete target;
	delete me;
	delete src;
}

void test9_DiscardFunctionality()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 9: Discard Function      ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	
	ICharacter* me = new Character("me");
	
	me->equip(new Ice());
	me->equip(new Cure());
	me->equip(new Ice());
	me->equip(new Cure());
	
	me->checkInventory();
	me->discard(1); // Delete immediately, no floor
	
	me->checkInventory();
	
	me->discard(1); // Should fail gracefully
	me->discard(10);
	
	std::cout << std::endl;

	delete me;
}

void test10_CrossCharacterEquipPrevention()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 10: Cross-Character Equip║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	
	ICharacter* alice = new Character("alice");
	ICharacter* bacon = new Character("bacon");
	
	AMateria* ice = new Ice();
	alice->equip(ice);
	
	std::cout << BOLD_C << "\n Alice's inventory:" << std::endl;
	alice->checkInventory();
	
	std::cout << BOLD_C << "\n Trying to equip Alice's materia to Bacon..." << RST << std::endl;
	bacon->equip(ice); // Should fail - already equipped by alice
	
	std::cout << BOLD_C << "\n Bacon's inventory (should be empty):" << std::endl;
	bacon->checkInventory();
	
	delete alice;
	delete bacon;
}

void test11_FloorFullScenario()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 11: Floor Full Scenario  ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	
	ICharacter* me = new Character("me");
	
	// Fill inventory and drop to floor
	for (int i = 0; i < MAX_FLOOR; ++i)
	{
		me->equip(new Ice());
		me->unequip(0);
	}
	
	std::cout << BOLD_C << "\n Floor is now full (" << MAX_FLOOR << " items)" << std::endl;
	
	// Try to unequip when floor is full
	me->equip(new Cure());
	std::cout << BOLD_C << "\n Trying to unequip when floor is full..." << RST << std::endl;
	me->unequip(0); // Should fail
	
	me->checkInventory();
	
	// But discard should still work!
	std::cout << BOLD_C << "\n Discarding instead (should work)..." << RST << std::endl;
	me->discard(0);
	me->checkInventory();
	
	delete me; // Will clean floor
}

void test12_MateriaSourceCopyOperations()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 12: MateriaSource Copy   ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	
	MateriaSource* src1 = new MateriaSource();
	src1->learnMateria(new Ice());
	src1->learnMateria(new Cure());
	
	// Test copy constructor
	std::cout << BOLD_C << "\n Creating copy of MateriaSource..." << RST << std::endl;
	MateriaSource* src2 = new MateriaSource(*src1);
	
	// Both should work independently
	AMateria* ice1 = src1->createMateria("ice");
	AMateria* ice2 = src2->createMateria("ice");
	
	if (ice1 && ice2)
		std::cout << " Both sources can create ice independently" << std::endl;
	
	delete ice1;
	delete ice2;
	
	// Test assignment operator
	MateriaSource src3;
	src3 = *src1;
	
	AMateria* cure = src3.createMateria("cure");
	if (cure)
		std::cout << " Assigned source can create cure" << std::endl;
	delete cure;
	
	delete src1;
	delete src2;
	// src3 will be destroyed automatically (stack)
}

void test13_MultipleCharactersSharedFloor()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 13: Multiple Char + Floor║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	
	ICharacter* char1 = new Character("char1");
	ICharacter* char2 = new Character("char2");
	ICharacter* char3 = new Character("char3");
	
	// Each character drops items
	char1->equip(new Ice());
	char1->unequip(0); // Floor: Ice
	
	char2->equip(new Cure());
	char2->unequip(0); // Floor: Ice, Cure
	
	char3->equip(new Ice());
	char3->unequip(0); // Floor: Ice, Cure, Ice
	
	std::cout << BOLD_C << "\n Three characters dropped items to shared floor" << std::endl;
	
	// Delete characters one by one
	delete char1;
	std::cout << " Deleted char1 - floor should persist" << std::endl;
	
	delete char2;
	std::cout << " Deleted char2 - floor should persist" << std::endl;
	
	delete char3;
	std::cout << " Deleted char3 (last character) - floor cleaned!" << std::endl;
}

void test14_UnequipThenReequip()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 14: Unequip Then Re-equip║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	
	ICharacter* me = new Character("me");
	AMateria* ice = new Ice();
	
	me->equip(ice);
	me->checkInventory();
	
	std::cout << BOLD_C << "\n Unequipping ice..." << RST << std::endl;
	me->unequip(0); // Ice on floor
	me->checkInventory();
	
	std::cout << BOLD_C << "\n Trying to re-equip same ice (from floor)..." << RST << std::endl;
	me->equip(ice); // Should work - ice has no holder now
	me->checkInventory();
	
	delete me; // Will clean ice
}

void test15_InvalidIndices()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 15: Invalid Indices      ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	
	ICharacter* me = new Character("me");
	ICharacter* target = new Character("target");
	
	me->equip(new Ice());
	
	std::cout << BOLD_C << "\n Testing negative index..." << RST << std::endl;
	me->use(-1, *target);
	me->unequip(-1);
	me->discard(-1);
	
	std::cout << BOLD_C << "\n Testing out-of-bounds index..." << RST << std::endl;
	me->use(999, *target);
	me->unequip(999);
	me->discard(999);
	
	delete target;
	delete me;
}

int main()
{
	{
		test1_CharacterIceCure();
	}
	{
		test2_MateriaSource();
	}
	{
		test3_UnequipAndGround();
	}
	{
		test4_CharacterDeepCopy();
	}
	{
		test5_CharacterAssignment();
	}
	{
		test6_InventoryOverflow();
	}
	{
		test7_MateriaSourceEdgeCases();
	}
	{
		test8_NullPointerHandling();
	}
	{
		test9_DiscardFunctionality();
	}
	{
		test10_CrossCharacterEquipPrevention();
	}
	{
		test11_FloorFullScenario();
	}
	{
		test12_MateriaSourceCopyOperations();
	}
	{
		test13_MultipleCharactersSharedFloor();
	}
	{
		test14_UnequipThenReequip();
	}
	{
		test15_InvalidIndices();
	}

	return 0;
}