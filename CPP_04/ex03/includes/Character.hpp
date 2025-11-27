/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/27 14:05:32 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "Utils.hpp"
#include "ICharacter.hpp"

class	Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* _inventory[INVENTORY_SIZE];

		static const int	_inventorySize = INVENTORY_SIZE;
		static const int	_maxFloor = MAX_FLOOR;
		static AMateria*	_floor[MAX_FLOOR];

		void	_initInventory();
		bool	_isValidIdx(int idx);
		bool	_isMateriaEquipable(AMateria* m);
		bool	_dropItem(AMateria& item)
		
	public:
		Character();
		Character(const std::string& name);
		Character(const Character& other);

		~Character();

		Character& operator=(const Character& other);
		
		std::string const& getName() const;
		
		// Inventory
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		void checkInventory();
};
#endif