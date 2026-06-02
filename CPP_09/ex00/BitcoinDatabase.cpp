/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinDatabase.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 13:58:47 by frbranda          #+#    #+#             */
/*   Updated: 2026/06/02 17:17:26 by frbranda         ###   ########.fr       */
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
	if (line.empty())
		throw BitcoinException("Empty data.csv empty.");
	if (line != "date,exchange_rate")
		throw BitcoinException("Bad data.csv header, expected: date,exchange_rate");

	while (std::getline(file, line))
	{
		line = trim(line);
		if (line.empty())
			throw (BitcoinException("data.csv empty line found!"));
			
		size_t comma = line.find(',');
		if (comma == std::string::npos)
			throw BitcoinException("data.csv bad line format: " + line);

		std::string date = line.substr(0, comma);
		if (!isValidDate(date))
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



/* ================================ Helpers ================================ */

std::string BitcoinDatabase::getClosestDate( const std::string& date) const
{
	dataIt it = _data.lower_bound(date);

	// Exact match
	if (it != _data.end() && it->first == date)
		return (it->first);
		
	// Date before entries
	if (it == _data.begin())
		return ("");

	--it;
	return (it->first);
}


float	BitcoinDatabase::getValue(const std::string& date) const
{
	dataIt it = _data.find(date);

	return (it->second);
}