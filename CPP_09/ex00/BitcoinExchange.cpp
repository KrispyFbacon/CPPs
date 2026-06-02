/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:53:27 by frbranda          #+#    #+#             */
/*   Updated: 2026/06/02 17:16:49 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string inputFile) 
	: _database(), _inputFile(inputFile) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	(void)other;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	(void)other;
	if (this != &other) {}

	return *this;
}


/* ================================= Helper ================================ */

void	BitcoinExchange::run()
{
	std::ifstream	file(_inputFile.c_str());
	if (!file.is_open())
		throw BitcoinException("Failed to open input file.");

	std::string	line;
	line = trim(line);
	std::getline(file, line);
	if (line.empty())
		throw BitcoinException("Empty input file.");
	if (line != "date | value")
		throw BitcoinException("Bad input header format, expected: date | value");

	while (std::getline(file, line))
	{
		line = trim(line);
		if (line.empty())
			continue;
			
		size_t pipe = line.find('|');
		if (pipe == std::string::npos)
		{
			printInvalid(line);
			continue;
		}

		std::string date = trim(line.substr(0, pipe));
		if (!isValidDate(date))
		{
			printInvalid(date);
			continue;
		}

		std::string	closestDate = _database.getClosestDate(date);
		if (closestDate.empty())
		{
			printError("no lower date available => " + date);
			continue ;
		}
		
		std::string	valueStr = trim(line.substr(pipe + 1));
		float value;
		if (!isValidValue(valueStr, value))
			continue;

		float result = value * _database.getValue(closestDate);

		std::cout << date << " => " << value << " = " << result << std::endl;
	}
}


/* ================================= PRIVATE =============================== */


void	BitcoinExchange::printError(const std::string& reason)
{
	std::cerr << "Error: " << reason << std::endl;
}


void	BitcoinExchange::printInvalid(const std::string& reason)
{
	std::cerr << "Error: bad input => " << reason << std::endl;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value)
{
	if (valueStr.empty())
	{
		printInvalid("empty value.");
		return false;
	}
	
	char	*endPtr;
	value = strtof(valueStr.c_str(), &endPtr);
	if (endPtr == valueStr.c_str() || *endPtr != '\0')
	{
		printInvalid(valueStr);
		return false;
	}

	if (value < 0)
	{
		printError("not a positive number.");
		return false;
	}

	if (value > 1000)
	{
		printError("too large of a number.");
		return false;
	}
	
	return true;
}