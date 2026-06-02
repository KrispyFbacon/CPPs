/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:53:25 by frbranda          #+#    #+#             */
/*   Updated: 2026/06/02 16:35:27 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "Utils.hpp"

#include "BitcoinDatabase.hpp"

class BitccoinDatabase;

class BitcoinExchange
{
	private:
		
		BitcoinDatabase	_database;
		std::string	_inputFile;
	
		BitcoinExchange();
		
		static void	printError(const std::string& str);
		static void	printInvalid(const std::string& str);
		
		bool isValidValue(const std::string& str, float& value);
		
	public:
		BitcoinExchange(const std::string inputFile);
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange();

		BitcoinExchange& operator=(const BitcoinExchange& other);

		void run();
};

#endif