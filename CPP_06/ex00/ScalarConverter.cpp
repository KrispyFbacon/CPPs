/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:20:42 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/16 19:02:54 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}


/* =============================== Checkers ================================ */

bool ScalarConverter::isChar(const std::string& str)
{
	return (str.length() == 3 && str[0] == '\'' 
			&& str[2] == '\'' && std::isprint(str[1]));
}

bool ScalarConverter::isInt(const std::string& str)
{
	size_t	i = 0;

	if ((str[i] == '+' || str[i] == '-') && str.length() != 1)
		i++;
	
	while (i < str.length())
	{
		if (!std::isdigit(str[i]))
			return false;
		++i;
	}
	
	return true;
}

bool ScalarConverter::isFloat(const std::string& str)
{
	if (str[str.length() - 1] != 'f')
		return false;

	size_t	i = 0;
	int		dot = 0;
	bool	hasDigit = false;

	if ((str[i] == '+' || str[i] == '-'))
		i++;
	
	while (i < str.length() - 1)
	{
		if (str[i] == '.')
		{
			dot++;
			if (dot > 1)
				return (false);
		}
		else if (std::isdigit(str[i]))
			hasDigit = true;
		else
			return false;
		++i;
	}

	return (dot == 1 && hasDigit);
}

bool ScalarConverter::isDouble(const std::string& str)
{
	size_t	i = 0;
	int		dot = 0;
	bool	hasDigit = false;

	if ((str[i] == '+' || str[i] == '-'))
		i++;
	
	while (i < str.length())
	{
		if (str[i] == '.')
		{
			dot++;
			if (dot > 1)
				return (false);
		}
		else if (std::isdigit(str[i]))
			hasDigit = true;
		else
			return false;
		++i;
	}

	return (dot == 1 && hasDigit);
}

int ScalarConverter::checkType(const std::string& str)
{
	if (str.empty())
		return (INVALID);
	
	if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
		return FLOAT;
	if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
		return DOUBLE;
		
	isType typeFuction[4] = {
		&isChar,
		&isInt,
		&isFloat,
		&isDouble
	};

	for (int i = 0 ; i < 4 ; ++i)
	{
		if (typeFuction[i](str))
			return i;
	}
	
	return INVALID;
}


/* ================================ Prints ================================= */

void ScalarConverter::printChar(char c)
{
	if (std::isprint(c))
		std::cout << "Char:   '" << c << "'" << std::endl;
	else
		std::cout << "Char:   non displayable" << std::endl;
}

void ScalarConverter::printInt(int i)
{
	std::cout << "Int:    " << i << std::endl;
}

void ScalarConverter::printFloat(float f)
{
	std::cout << "Float:  " << std::showpoint << f << std::endl;
}

void ScalarConverter::printDouble(double d)
{
	std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::printImpossible(scalarType type)
{
	switch (type)
	{
		case CHAR:
			std::cout << "Char:   ";
			break;
		case INT:
			std::cout << "Int:    ";
			break;
		case FLOAT:
			std::cout << "Float:  ";
			break;
		case DOUBLE:
			std::cout << "Double: ";
			break;
		default:
			std::cout << ":";
	}
	std::cout << "Impossible" << std::endl;
}

void ScalarConverter::printInvalid()
{
	printImpossible(CHAR);
	printImpossible(INT);
	printImpossible(FLOAT);
	printImpossible(DOUBLE);
}


/* =============================== Handlers ================================ */

void ScalarConverter::handleChar(char c)
{
	printChar(c);
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void ScalarConverter::handleInt(int i)
{
	if (i < 0 || i > 127)
		printImpossible(CHAR);
	else
		printChar(static_cast<char>(i));
	
	printInt(i);
	printFloat(static_cast<float>(i));
	printDouble(static_cast<double>(i));
}

// void handleFloat(float f);
// void handleDouble(double d);

void ScalarConverter::convert(const std::string& str)
{
	switch (checkType(str))
	{
		case CHAR:
			handleChar(str[1]);
			break;
		case INT:
			std::cout << "IS INT" << std::endl;
			handleInt(static_cast<int>(std::strtol(str.c_str(), NULL, 10)));
			break;
		case FLOAT:
			std::cout << "IS FLOAT" << std::endl;
			break;
		case DOUBLE:
			std::cout << "IS DOUBLE" << std::endl;
			break;
		default:
			printInvalid();
			std::cerr << BOLD_R <<"Error: Invalid type" << RST << std::endl;
	}
}