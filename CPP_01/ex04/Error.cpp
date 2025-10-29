/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:54:00 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/29 15:05:25 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.hpp"

void Error::error(const std::string &error)
{
	std::cout << BOLD_R << "ERROR: " << RST << std::endl;
	std::cout << BOLD_R << error << RST << std::endl;
}

void Error::open(const std::string &filename)
{
	std::cout << BOLD_R << "ERROR: " RST << std::endl;
	std::cout << BOLD_R << "Failed to open file "
			  << BOLD_W << filename
			  << RST << std::endl;
}
