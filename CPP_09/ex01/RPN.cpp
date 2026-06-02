/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:28:26 by frbranda          #+#    #+#             */
/*   Updated: 2026/06/02 17:58:53 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other)
{
	(void)other;
}

RPN& RPN::operator=(const RPN& other)
{
	(void)other;
	if (this != &other) {}

	return *this;
}

RPN::RPN(const std::string& str) 
{
	
}

RPN::~RPN() {}


/* ================================= PRIVATE =============================== */

bool	RPN::isValidToken(const std::string& token ) const
{
	//TODO
}

bool	RPN::isOperation(const char c ) const
{
	//TODO
}

void	RPN::solve(const char c)
{
	
}