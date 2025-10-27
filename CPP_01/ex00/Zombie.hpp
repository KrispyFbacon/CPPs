/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/27 17:16:31 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <iomanip>
#include <string>

# define RST	"\033[0m"
# define CLEAR	"\033[2J\033[H"
# define R		"\033[0;31m"
# define G		"\033[0;32m"
# define Y		"\033[0;33m"

# define BOLD_C		"\033[1;36m"
# define BOLD_W		"\033[1;37m"

# define Z_COLOR Y

class	Zombie
{
	private:
		std::string _name;

	public:
		Zombie(const std::string &name);
		~Zombie();
		
		// setter
		void	setName(const std::string &name);

		// getter
		std::string getName() const;

		void announce( void );
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif