/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:28:30 by frbranda          #+#    #+#             */
/*   Updated: 2026/06/02 17:59:07 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iomanip>
#include <stack>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

class RPN
{
	private:
		std::stack<int>	_stack;

		bool	isValidToken( const std::string& token ) const;
		bool	isOperation( const char c ) const;

		void	RPN::solve(const char c);
		
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		
	public:
		RPN(const std::string& str);
		~RPN();
};


// --- Template Functions ---
template <typename T>
std::string toString(T src)
{
	std::stringstream ss;
	ss << src;
	return ss.str();
}

#endif
