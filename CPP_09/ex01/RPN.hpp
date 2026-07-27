/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:28:30 by frbranda          #+#    #+#             */
/*   Updated: 2026/07/27 18:39:43 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iomanip>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>

class RPN
{
	private:
		bool isOperator(const std::string& token) const;
		bool isNumber(const std::string& token) const;
		int  applyOperator(int a, int b, const std::string& op) const;
		
		
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);

	public:
		RPN();
		~RPN();

		int calculate(const std::string& expression) const;
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
