/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/28 17:07:48 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <iomanip>
#include <string>

// reset color / clean terminal
# define RST	"\033[0m"
# define CLEAR	"\033[2J\033[H"

//color
# define BLACK	"\033[0;30m"
# define R		"\033[0;31m"
# define G		"\033[0;32m"
# define Y		"\033[0;33m"
# define B		"\033[0;34m"
# define M		"\033[0;35m"
# define C		"\033[0;36m"
# define W		"\033[0;37m"

//bold color
# define BOLD_Y		"\033[1;33m"
# define BOLD_M		"\033[1;35m"
# define BOLD_C		"\033[1;36m"
# define BOLD_W		"\033[1;37m"

# define Z_COLOR Y

class	Zombie
{
	private:
		std::string _name;

	public:
		Zombie();
		Zombie(const std::string &name);
		~Zombie();
		
		void	setName(const std::string &name);
		std::string getName() const;

		void announce( void );
};

Zombie* zombieHorde( int N, std::string name );

#endif