/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinDatabase.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 13:58:47 by frbranda          #+#    #+#             */
/*   Updated: 2026/06/01 16:39:27 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinDatabase.hpp"

const std::string BitcoinDatabase::_dataFile = "data.csv";

BitcoinDatabase::BitcoinDatabase()
{
	std::ifstream	file(_dataFile.c_str());

	if (!file.is_open())
		throw BitcoinException("Failed to open required data.csv file.");

	std::string	line;
	line = trim(line);
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw BitcoinException("data.csv format should be: date,exchange_rate.");

	while (std::getline(file, line))
	{
		line = trim(line); 
		if (line.empty())
			throw (BitcoinException("data.csv empty line found!"));
			
		size_t comma = line.find(',');
		if (comma == std::string::npos)
			throw BitcoinException("data.csv bad line format: " + line);

		std::string date = line.substr(0, comma);
		if (!isDateValid(date))
			throw BitcoinException("data.csv invalid date: " + date);

		char*	endPtr;
		std::string	rateStr = line.substr(comma + 1);
		float rate = strtof(rateStr.c_str(), &endPtr);
		if (endPtr == rateStr.c_str() || rate < 0)
			throw BitcoinException("data.csv invalid rate: " + rateStr);
			
		_data[date] = rate;
	}
}

BitcoinDatabase::BitcoinDatabase(const BitcoinDatabase& other)
{
	(void)other;
}

BitcoinDatabase::~BitcoinDatabase() {}

BitcoinDatabase& BitcoinDatabase::operator=(const BitcoinDatabase& other)
{
	(void)other;
	if (this != &other) {}

	return *this;
}
