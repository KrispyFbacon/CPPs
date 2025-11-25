/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/25 12:59:45 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "Utils.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

#define MAX_INVENTORY 4

class	Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* _inventory[MAX_INVENTORY];

		static int	_inventorySpace;

		//void	init_inventory();
		
	public:
		Character();
		Character(const std::string& name);
		Character(const Character& other);

		~Character();

		Character& operator=(const Character& other);
		
		// getters
		std::string const& getName() const;
		
		// Inventory
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		void checkInventory();
};
#endif