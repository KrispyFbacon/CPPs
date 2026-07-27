/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:28:26 by frbranda          #+#    #+#             */
/*   Updated: 2026/07/27 19:03:05 by frbranda         ###   ########.fr       */
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

RPN::~RPN() {}

int RPN::calculate(const std::string& expression) const
{
	std::stack<int, std::list<int> > stack;
	std::stringstream	ss(expression);
	std::string			token;

	while (ss >> token) // just like std::cin but instead of reading from keyboard it reads from string
	{
		if (isNumber(token))
			stack.push(std::atoi(token.c_str()));
		
		else if (isOperator(token))
		{
			if (stack.size() < 2)
				throw std::runtime_error("insuficcient operands(numbers)");

			int b = stack.top();
			stack.pop();

			int a = stack.top();
			stack.pop();

			stack.push(applyOperator(a, b, token));
		}

		else
			throw std::runtime_error("invalid token.");
	}


	if (stack.size() != 1)
		throw std::runtime_error("invalid expression.");

	return stack.top();
}

/* ================================= PRIVATE =============================== */

bool RPN::isOperator(const std::string& token) const
{
	return ((token == "+" || token == "-" || token == "*" || token == "/")
			&& token.length() == 1);
}

bool RPN::isNumber(const std::string& token) const
{
	return (std::isdigit(static_cast<unsigned char>(token[0])) 
			&& token.length() == 1);
}

int  RPN::applyOperator(int a, int b, const std::string& op) const
{
	if (op == "+")
		return a + b;

	if (op == "-")
		return a - b;
		
	if (op == "*")
		return a * b;
		
	if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("divided by zero.");
		return a / b;
	}

	throw std::runtime_error("unknown operator.");
}


// Notes:

// NOTE 1:

//template <class T, class Container = std::deque<T> >
// class stack;

// Two template parameters: T = the element type, Container = what to store them in, defaulting to std::deque<T> if you don't specify it.



// ---- NOTE 2:

// std::stack<int, std::list<int> > stack;

// Means:
// -Store ints.
// -Use a std::list<int> internally.
// -Only allow stack operations (push, pop, top, empty, size).

// You cannot access the list directly.



// NOTE 3:

//By default:
// std::stack<int> s;

// is actually equivalent to:
// std::stack<int, std::deque<int> > s;