/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/24 16:52:11 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include "Color.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

/* Class and identifier colors */
#define CLASS_COLOR	BOLD_Y
#define NAME_COLOR	RGB_BOLD(100, 150, 250)
#define NUM_COLOR	RGB_BOLD(255, 165, 0)

/* Action colors */
#define ICE_COLOR	RGB_BOLD(150, 200, 255)
//RGB_BOLD(120, 180, 255)
//RGB_BOLD(180, 220, 255)
#define HEAL_COLOR	RGB(152, 251, 152)

class	Utils
{
	public:
		virtual void f()const = 0;
};
#endif