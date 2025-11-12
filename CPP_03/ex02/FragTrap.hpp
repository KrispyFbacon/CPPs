/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/12 18:00:56 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#define HIGHFIVE_COLOR  RGB_BOLD(255, 105, 180)

class	FragTrap : public ClapTrap
{
	private:
		void _initFragStats();
		
	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& other);

		~FragTrap();

		FragTrap& operator=(const FragTrap& other);

		void attack(const std::string& target);
		void highFivesGuys(void);
};


#endif