/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinDatabase.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 13:58:27 by frbranda          #+#    #+#             */
/*   Updated: 2026/06/09 13:58:43 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINDATABASE_HPP
# define BITCOINDATABASE_HPP

#include "Utils.hpp"

class BitcoinDatabase
{
	private:
		typedef std::map<std::string, float>::const_iterator	dataIt;
		
		static const std::string		_dataFile;
		std::map<std::string, float>	_data;
		
		BitcoinDatabase(const BitcoinDatabase& other);
		BitcoinDatabase& operator=(const BitcoinDatabase& other);
		
	public:
		BitcoinDatabase();
		~BitcoinDatabase();

		std::string	getClosestDate(const std::string& date) const;
		float	getValue(const std::string& date) const;
};

#endif