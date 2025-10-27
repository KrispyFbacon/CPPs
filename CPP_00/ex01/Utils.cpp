/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:48:18 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/27 13:08:25 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

std::string	trim(const std::string &str)
{
	size_t start = 0;
	size_t end = str.length();

	while (start < end && std::isspace(str[start]))
		start++;
		
	while (end > start && std::isspace(str[end - 1]))
		end--;
		
	return str.substr(start, end - start);
}

bool	isValidName(const std::string &str)
{
	size_t	i;
	
	for (i = 0; i < str.length(); i++)
	{
		if (!std::isalpha(str[i]))
			return false;
	}
	return true;
}

bool	isValidNumber(const std::string &str)
{
	size_t	i;
	
	for (i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}