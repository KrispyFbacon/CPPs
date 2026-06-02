/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:10:36 by frbranda          #+#    #+#             */
/*   Updated: 2026/06/02 16:43:03 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

bool	isValidDate(const std::string& date)
{
	if (date.length() != 10)
		return false;
		
	if (date[4] != '-' || date[7] != '-')
		return false;
		
	for (size_t i = 0; i < 10; i++)
	{
		if (i != 4 && i != 7 && !isdigit(date[i]))
			return (false);
	}
	
	int	year = atoi(date.substr(0, 4).c_str());
	int	month = atoi(date.substr(5, 2).c_str());
	int	day = atoi(date.substr(8, 2).c_str());

	if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	
	if (month == 2)
	{
		bool isLeap = ((year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0);
		if (day > (isLeap ? 29 : 28))
			return false;
	} 
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
			return false;
			
	return true;
}

std::string	trim(const std::string& str)
{
	size_t	first = str.find_first_not_of(" \t\r\n");

	if (first == std::string::npos)
		return ("");
		
	size_t	last = str.find_last_not_of(" \t\r\n");

	return (str.substr(first, last - first + 1));
}