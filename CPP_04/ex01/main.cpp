/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:28:27 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/18 16:18:16 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define ARRAY_SIZE 8

int main()
{
	std::cout << BOLD_C << "╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 1: Array size            ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		const Animal* animal[ARRAY_SIZE];

		for (int i = 0; i < ARRAY_SIZE; ++i)
		{
			if (i % 2 == 0)
				animal[i] = new Dog();
			else
				animal[i] = new Cat();
		}

		std::cout << std::endl;
		
		for (int i = 0; i < ARRAY_SIZE; ++i)
		{
			std::cout << "Animal[" << NUM_COLOR << i << RST << "]: " 
					  << NAME_COLOR << animal[i]->getType() 
					  << RST << std::endl;
			animal[i]->makeSound();
		}
		
		std::cout << std::endl;

		for (int i = 0; i < ARRAY_SIZE; ++i)
			delete animal[i];
	}
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 2: Deep Copy             ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		std::cout << "\n" << BOLD_M << "Creating original dog!" << RST << std::endl;
		Dog* original = new Dog();
		original->getBrain()->setIdea(0, "I am original");
		
		std::cout << "\n" << BOLD_M << "Creating copy of dog!" << RST << std::endl;
		Dog* copy = new Dog(*original);

		std::cout << "\n" << BOLD_M << "Checking Brain addresses:" << RST << std::endl;
		std::cout << "Original Brain: " << NAME_COLOR << original->getBrain() << RST << std::endl;
		std::cout << "Copy Brain:     " << NAME_COLOR << copy->getBrain() << RST << std::endl;

		std::cout << "\n" << BOLD_M << "Checking Brain values:" << RST << std::endl;
		std::cout << "Original idea[" << NUM_COLOR << "0" << RST << "]: " << NAME_COLOR << original->getBrain()->getIdea(0) << RST << std::endl;
		std::cout << "Copy idea[" << NUM_COLOR << "0" << RST << "]:     " << NAME_COLOR << copy->getBrain()->getIdea(0) << RST << std::endl;

		std::cout << "\n" << BOLD_M << "Modifying copy's brain..." << RST << std::endl;
		copy->getBrain()->setIdea(0, "I am copy");
		
		std::cout << "Original idea[" << NUM_COLOR << "0" << RST << "]: " << NAME_COLOR << original->getBrain()->getIdea(0) << RST << std::endl;
		std::cout << "Copy idea[" << NUM_COLOR << "0" << RST << "]:     " << NAME_COLOR << copy->getBrain()->getIdea(0) << RST << std::endl;

		std::cout << std::endl;
		delete original;
		delete copy;
	}
	
	return 0;
}
