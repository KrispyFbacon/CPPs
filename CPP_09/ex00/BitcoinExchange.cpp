/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:53:27 by frbranda          #+#    #+#             */
/*   Updated: 2026/06/01 18:09:52 by frbranda         ###   ########.fr       */
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

void	BitcoinExchange::run()
{
	std::ifstream	file(_inputFile.c_str());
	if (!file.is_open())
		throw BitcoinException("Failed to open input file.");

	std::string	line;
	line = trim(line);
	std::getline(file, line);
	if (line != "date | value")
		throw BitcoinException("Invalid input file column format, should be: date | value");
	
	
}