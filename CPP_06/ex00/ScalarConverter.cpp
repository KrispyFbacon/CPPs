/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:20:42 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/17 16:58:46 by frbranda         ###   ########.fr       */
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

	char* end;
	errno = 0;
	
	long l = std::strtol(str.c_str(), &end, 10);
	
	return (*end == '\0' && errno != ERANGE && l >= INT_MIN && l <= INT_MAX);

}

bool ScalarConverter::isFloat(const std::string& str)
{
	if (str[str.length() - 1] != 'f')
		return false;

	char* end;
	errno = 0;
	
	std::strtof(str.c_str(), &end);
	
	return (*end == 'f' && *(end + 1) == '\0' && errno != ERANGE);
}

bool ScalarConverter::isDouble(const std::string& str)
{
	char* end;
	errno = 0;
	
	std::strtod(str.c_str(), &end);
	
	return (*end == '\0' && errno != ERANGE);
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
	if (f == static_cast<int>(f) && std::abs(f) < 1e6f
				&& !std::isinf(f) && !std::isnan(f))
	{
		std::cout << "Float:  " << std::fixed << std::setprecision(1)
			  << f << "f" << std::endl;
	}
	else
		std::cout << "Float:  " << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d)
{
	if (d == static_cast<int>(d) && std::abs(d) < 1e15
				&& !std::isinf(d) && !std::isnan(d))
	{
		std::cout << "Double: " << std::fixed << std::setprecision(1)
			<< d << std::endl;
	}
	else
		std::cout << "Double: " << d << std::endl;
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

void ScalarConverter::handleFloat(float f)
{
	if ( std::isnan(f) || std::isinf(f))
	{
		printImpossible(CHAR);
		printImpossible(INT);
		printFloat(f);
		printDouble(static_cast<double>(f));
		return ;
	}
	
	if (f < 0 || f > 127)
		printImpossible(CHAR);
	else
		printChar(static_cast<char>(f));
	
	if (f < INT_MIN || static_cast<int>(f) > INT_MAX)
		printImpossible(INT);
	else
		printInt(static_cast<int>(f));
	
	printFloat(f);
	printDouble(static_cast<double>(f));
}

void ScalarConverter::handleDouble(double d)
{
	if ( std::isnan(d) || std::isinf(d))
	{
		printImpossible(CHAR);
		printImpossible(INT);
		printFloat(static_cast<float>(d));
		printDouble(d);
		return;
	}

	if (d < 0 || d > 127)
		printImpossible(CHAR);
	else
		printChar(static_cast<char>(d));
	
	if (d < INT_MIN || d > INT_MAX)
		printImpossible(INT);
	else
		printInt(static_cast<int>(d));
	
	if (d < -FLT_MAX || d > FLT_MAX)
		printImpossible(FLOAT);
	else
		printFloat(static_cast<float>(d));
	
	printDouble(d);
}

void ScalarConverter::convert(const std::string& str)
{
	switch (checkType(str))
	{
		case CHAR:
			handleChar(str[1]);
			break;
		case INT:
			handleInt(static_cast<int>(std::strtol(str.c_str(), NULL, 10)));
			break;
		case FLOAT:
			handleFloat((std::strtof(str.c_str(), NULL)));
			break;
		case DOUBLE:
			handleDouble((std::strtod(str.c_str(), NULL)));
			break;
		default:
			std::cerr << BOLD_R <<"Error: Invalid type" << RST << std::endl;
			printInvalid();
	}
}