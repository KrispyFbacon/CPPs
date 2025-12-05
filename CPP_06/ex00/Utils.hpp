/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/05 16:35:37 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>		// input/output
#include <iomanip>		// formatting output, stew
#include <string>		// std::string
#include <sstream>		// stringstream
#include "Color.hpp"	// My color library

/* Class and identifier colors */
#define CLASS_COLOR		BOLD_Y
#define NAME_COLOR		RGB_BOLD(100, 150, 250)
#define FORM_COLOR		RGB_BOLD(180, 120, 255)
#define TARGET_COLOR	RGB_BOLD(255, 80, 80)
#define NUM_COLOR		RGB_BOLD(255, 165, 0)

#define BOLD_O RGB_BOLD(220, 69, 0)

//std::string intToString(int num);

#endif