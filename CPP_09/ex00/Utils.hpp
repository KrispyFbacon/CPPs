/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:55:17 by frbranda          #+#    #+#             */
/*   Updated: 2026/06/02 16:32:52 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <map>

#include "Exceptions.hpp"

// --- Template Functions ---
template <typename T>
std::string toString(T src)
{
	std::stringstream ss;
	ss << src;
	return ss.str();
}

bool	isValidDate(const std::string& date);
std::string	trim(const std::string& str);




#endif