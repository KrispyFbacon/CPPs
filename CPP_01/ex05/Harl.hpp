/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:15:12 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/30 12:30:45 by frbranda         ###   ########.fr       */
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
# define R		"\033[0;31m"
# define G		"\033[0;32m"
# define W		"\033[0;37m"

//bold color
# define BOLD_R		"\033[1;31m"
# define BOLD_G		"\033[1;32m"
# define BOLD_Y		"\033[1;33m"
# define BOLD_B		"\033[1;34m"
# define BOLD_M		"\033[1;35m"
# define BOLD_C		"\033[1;36m"
# define BOLD_W		"\033[1;37m"

class	Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	
	public:
		Harl();
		~Harl();
		
		void complain( std::string level );

};

#endif