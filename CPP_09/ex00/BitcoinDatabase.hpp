/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinDatabase.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 13:58:27 by frbranda          #+#    #+#             */
/*   Updated: 2026/06/01 16:08:29 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINDATABASE_HPP
#define BITCOINDATABASE_HPP

#include "Utils.hpp"

class BitcoinDatabase
{
	private:
		static const std::string	_dataFile;
		
		std::map<std::string, float>	_data;

	public:
		BitcoinDatabase();
		BitcoinDatabase(const BitcoinDatabase& other);
		~BitcoinDatabase();

		BitcoinDatabase& operator=(const BitcoinDatabase& other);
};

#endif