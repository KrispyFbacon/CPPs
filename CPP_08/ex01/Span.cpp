/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:33:40 by frbranda          #+#    #+#             */
/*   Updated: 2026/01/21 15:11:55 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _numbs(other._numbs), _maxSize(other._maxSize) {}

Span::~Span() {}

Span& Span::operator=(const Span& other)
{
	if (this != &other) 
	{
		_maxSize = other._maxSize;
		_numbs = other._numbs;
	}

	return *this;
}

void Span::addNumber(int nbr)
{
	if (_numbs.size() >= static_cast<size_t>(_maxSize))
		throw SpanFullException();
		
	_numbs.push_back(nbr);
}

void Span::addRange(int begin, int end)
{
	if (begin > end)
		throw std::invalid_argument("Invalid range");
	
	size_t count = static_cast<size_t>(end - begin);
	if (_numbs.size() + count > _maxSize)
		throw SpanFullException();
		
	for (int i = begin ; i < end; ++i)
		this->_numbs.push_back(i);
}


int Span::shortestSpan()
{
	if (_numbs.size() <= 1)
		throw SpanTooLittleException();

	std::vector<int> temp = _numbs;
	
	std::sort(temp.begin(), temp.end());
	std::adjacent_difference(temp.begin(), temp.end(), temp.begin());
		
	return (*std::min_element(temp.begin() + 1, temp.end()));
}

int Span::longestSpan()
{
	if (_numbs.size() <= 1)
		throw SpanTooLittleException();

	int biggest = *std::max_element(_numbs.begin(), _numbs.end());
	int smallest = *std::min_element(_numbs.begin(), _numbs.end());

	return (biggest - smallest);
}


/* ============================== Exceptions =============================== */

const char* Span::SpanTooLittleException::what() const throw()
{
	return ("Not enough Span elements");
}

const char* Span::SpanFullException::what() const throw()
{
	return ("Span vector is full!");
}
