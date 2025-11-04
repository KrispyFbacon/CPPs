/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/04 12:00:34 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

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
# define BOLD_B		"\033[1;34m"
# define BOLD_M		"\033[1;35m"
# define BOLD_C		"\033[1;36m"
# define BOLD_W		"\033[1;37m"

// Options
# define WEAPON		BOLD_Y
# define HUMAN		BOLD_C

class	Weapon
{
	private:
		std::string _type;

		Weapon();
		
	public:
		Weapon(const std::string &type);
		~Weapon();
		
		void	setType(const std::string &type);
		const std::string& getType() const;
};

#endif