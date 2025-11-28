/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:28:27 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/20 16:46:53 by frbranda         ###   ########.fr       */
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
		//const Animal test;

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
		original->getBrain().setIdea(0, "I am original");
		
		std::cout << "\n" << BOLD_M << "Creating copy of dog!" << RST << std::endl;
		Dog* copy = new Dog(*original);

		std::cout << "\n" << BOLD_M << "Checking Brain addresses:" << RST << std::endl;
		std::cout << "Original Brain: " << NAME_COLOR << &original->getBrain() << RST << std::endl;
		std::cout << "Copy Brain:     " << NAME_COLOR << &copy->getBrain() << RST << std::endl;

		std::cout << "\n" << BOLD_M << "Checking Brain values:" << RST << std::endl;
		std::cout << "Original idea[" << NUM_COLOR << "0" << RST << "]: " << NAME_COLOR << original->getBrain().getIdea(0) << RST << std::endl;
		std::cout << "Copy idea[" << NUM_COLOR << "0" << RST << "]:     " << NAME_COLOR << copy->getBrain().getIdea(0) << RST << std::endl;

		std::cout << "\n" << BOLD_M << "Modifying copy's brain..." << RST << std::endl;
		copy->getBrain().setIdea(0, "I am copy");
		//copy->getBrain().setIdea(0, "I am copy");
		
		std::cout << "Original idea[" << NUM_COLOR << "0" << RST << "]: " << NAME_COLOR << original->getBrain().getIdea(0) << RST << std::endl;
		std::cout << "Copy idea[" << NUM_COLOR << "0" << RST << "]:     " << NAME_COLOR << copy->getBrain().getIdea(0) << RST << std::endl;

		std::cout << std::endl;
		delete original;
		delete copy;
	}
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 3: Assignment Operator   ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		Dog dog1;
		dog1.getBrain().setIdea(0, "Dog 1 idea");
		
		Dog dog2;
		dog2.getBrain().setIdea(0, "Dog 2 idea");
		
		std::cout << "\n" << BOLD_M << "Before assignment:" << RST << std::endl;
		std::cout << "dog1 idea: " << NAME_COLOR << dog1.getBrain().getIdea(0) << RST << std::endl;
		std::cout << "dog2 idea: " << NAME_COLOR << dog2.getBrain().getIdea(0) << RST << std::endl;
		
		std::cout << "\n" << BOLD_M << "Assigning dog1 = dog2" << RST << std::endl;
		dog1 = dog2;
		
		std::cout << "\n" << BOLD_M << "After assignment:" << RST << std::endl;
		std::cout << "dog1 idea: " << NAME_COLOR << dog1.getBrain().getIdea(0) << RST << std::endl;
		std::cout << "dog2 idea: " << NAME_COLOR << dog2.getBrain().getIdea(0) << RST << std::endl;
		
		std::cout << "\n" << BOLD_M << "Modifying dog2..." << RST << std::endl;
		dog2.getBrain().setIdea(0, "Dog 2 MODIFIED");
		
		std::cout << "dog1 idea: " << NAME_COLOR << dog1.getBrain().getIdea(0) << RST << std::endl;
		std::cout << "dog2 idea: " << NAME_COLOR << dog2.getBrain().getIdea(0) << RST << std::endl;
		
		std::cout << std::endl;
	}
	
	return 0;
}
