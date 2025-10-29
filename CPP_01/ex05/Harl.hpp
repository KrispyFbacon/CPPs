/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:15:12 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/29 17:32:08 by frbranda         ###   ########.fr       */
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