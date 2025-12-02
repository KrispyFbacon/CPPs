/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/02 18:58:37 by frbranda         ###   ########.fr       */
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
#define FORM_COLOR	RGB_BOLD(120, 255, 120)
#define NUM_COLOR	RGB_BOLD(255, 165, 0)

#define O RGB(220, 69, 0)

void printError(const std::string& msg);

#endif