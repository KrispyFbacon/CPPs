/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:28:30 by frbranda          #+#    #+#             */
/*   Updated: 2026/07/27 20:38:00 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <list>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <cctype>
#include <string>

class RPN
{
	private:
		bool	isOperator(const std::string& token) const;
		bool	isNumber(const std::string& token) const;
		int		applyOperator(int a, int b, const std::string& op) const;
		
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		int	calculate(const std::string& expression) const;
};

#endif
