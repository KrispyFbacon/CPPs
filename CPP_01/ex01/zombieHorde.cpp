/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:22:05 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/18 13:54:04 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* newHorde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		newHorde[i].setName(name);
		std::cout << W <<"Set name Zombie[" 
				  << M << i
				  << W << "]: "
				  << Z_COLOR << newHorde[i].getName() 
				  << RST << std::endl;
	}
	return (newHorde);
}