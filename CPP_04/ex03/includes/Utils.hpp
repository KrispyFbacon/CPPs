/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/27 13:40:56 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Color.hpp"


/* Class and identifier colors */
#define CLASS_COLOR	BOLD_Y
#define NAME_COLOR	RGB_BOLD(100, 150, 250)
#define NUM_COLOR	RGB_BOLD(255, 165, 0)

/* Materia colors */
#define MATE_COLOR  RGB_BOLD(170, 120, 255)
#define ICE_COLOR	RGB_BOLD(150, 200, 255)
#define HEAL_COLOR	RGB(152, 251, 152)

/* Game Options*/
#define INVENTORY_SIZE 4
#define MAX_FLOOR 20

void printError(const std::string& msg);
std::string printType(const std::string& type);


#endif