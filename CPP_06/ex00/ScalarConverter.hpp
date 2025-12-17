/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/17 17:03:35 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include "Utils.hpp"

class ScalarConverter
{
	private:
		enum scalarType
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			INVALID
		};
		
		typedef bool (*isType)(const std::string&);
		
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter();
		ScalarConverter operator=(const ScalarConverter& other);
		
		
		static bool isChar(const std::string& str);
		static bool isInt(const std::string& str);
		static bool isFloat(const std::string& str);
		static bool isDouble(const std::string& str);
		
		static int checkType(const std::string& str);
		
		static void printChar(char c);
		static void printInt(int i);
		static void printFloat(float f);
		static void printDouble(double d);
		static void printImpossible(scalarType type);
		static void printInvalid();

		static void handleChar(char c);
		static void handleInt(int n);
		static void handleFloat(float f);
		static void handleDouble(double d);
		
	public:
		static void convert(const std::string& str);
};



#endif