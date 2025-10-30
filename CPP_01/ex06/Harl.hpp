/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:15:12 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/30 18:08:38 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

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
# define BOLD_R		"\033[1;31m"
# define BOLD_G		"\033[1;32m"
# define BOLD_Y		"\033[1;33m"
# define BOLD_B		"\033[1;34m"
# define BOLD_M		"\033[1;35m"
# define BOLD_C		"\033[1;36m"
# define BOLD_W		"\033[1;37m"

enum levelType
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	INVALID
};

class	Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

		void	switchFilter(int levelIndex);
	public:
		Harl();
		~Harl();
		
		void	complain( std::string level );
};

#endif