/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/06 10:42:46 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

// reset color / clear terminal
# define RST	"\033[0m"
# define CLEAR	"\033[2J\033[H"

// color
# define R		"\033[0;31m"
# define G		"\033[0;32m"
# define Y		"\033[0;33m"

class	Fixed
{
	private:
		int					_value;
		static const int	_bits;
		
	public:
		// Orthodox Canonical Form
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		// Extra Constructors
		Fixed(const int num);
		Fixed(const float num);


		float toFloat( void ) const;
		int toInt( void ) const;

		void setRawBits( int const raw );
		int getRawBits( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixedPoint);

#endif