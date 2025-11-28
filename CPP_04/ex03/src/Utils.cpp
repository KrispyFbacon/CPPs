/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:54:28 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/26 16:31:56 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

void	printError(const std::string& msg)
{
	std::cerr << BOLD_R << "Error: "
			  << RST << msg << std::endl;
}

std::string printType(const std::string& type)
{
	if (type == "ice")
		return ICE_COLOR + type + RST;
		
	else if (type == "cure")
		return HEAL_COLOR + type + RST;

	return MATE_COLOR + type + RST;
}