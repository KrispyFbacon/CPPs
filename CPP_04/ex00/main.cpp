/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:28:27 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/20 17:24:55 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << BOLD_C << "╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 1: Given main            ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* a = new Dog();
		const Animal* b = new Cat();

		std::cout << std::endl;
		std::cout << a->getType() << " " << std::endl;
		std::cout << b->getType() << " " << std::endl;
		std::cout << meta->getType() << " " << std::endl;
		std::cout << std::endl;
		
		a->makeSound();
		(*a).makeSound();
		b->makeSound(); //will output the cat sound!
		b[0].makeSound();
		meta->makeSound();
		
		std::cout << std::endl;

		delete meta;
		delete a;
		delete b;
		
	}
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 2: Wrong given main      ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		const WrongAnimal* wMeta = new WrongAnimal();
		const WrongAnimal* wA = new WrongCat();

		std::cout << std::endl;
		std::cout << wA->getType() << " " << std::endl;
		std::cout << wMeta->getType() << " " << std::endl;
		std::cout << std::endl;
		
		wA->makeSound();
		wMeta->makeSound();
		
		std::cout << std::endl;

		delete wMeta;
		delete wA;
		
	}
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 3: Crazy test            ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		const Animal* meta[3] = {
			new Animal(),
			new Cat(),
			new Dog()
		};
		
		std::cout << std::endl;
		for (int i = 0; i < 3; ++i)
		{
			std::cout << meta[i]->getType() << std::endl;
			meta[i]->makeSound();
		}
		std::cout << std::endl;
		
		for (int i = 0; i < 3; i++)
			delete meta[i];
		
	}
	std::cout << BOLD_C << "\n╔════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 4: Animal                ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════╝" << RST << std::endl;
	{
		Animal	animal;
		Cat		cat;
		Dog		dog;

		std::cout << std::endl;

		animal.makeSound();
		cat.makeSound();
		cat.Animal::makeSound();
		dog.makeSound();
		
		std::cout << std::endl;
		
		WrongAnimal	wAnimal;
		WrongCat	wCat;

		std::cout << std::endl;
		
		wAnimal.makeSound();
		wCat.makeSound();

		std::cout << std::endl;

	}
	return 0;
}
