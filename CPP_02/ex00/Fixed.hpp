/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/31 16:08:59 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <iomanip>
#include <string>

// reset color / clear terminal
# define RST	"\033[0m"
# define CLEAR	"\033[2J\033[H"

// color
# define R		"\033[0;31m"
# define G		"\033[0;32m"

// bold color
# define BOLD_R		"\033[1;31m"
# define BOLD_G		"\033[1;32m"


class	Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed& other); //Copy constructor
		Fixed& operator=(const Fixed& other); // Copy assignment operator (not constructer)
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};


#endif