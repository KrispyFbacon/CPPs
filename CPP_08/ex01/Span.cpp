/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:33:40 by frbranda          #+#    #+#             */
/*   Updated: 2026/01/16 17:49:57 by frbranda         ###   ########.fr       */
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


int Span::shortestSpan()
{
	if (_maxSize <= 1)
		throw SpanTooLittleException();

	std::vector<int> sortNumbs = _numbs;
	
	std::sort(sortNumbs.begin(), sortNumbs.end());
	std::adjacent_difference(sortNumbs.begin(), sortNumbs.end(), sortNumbs.begin());
		
	return (*std::min_element(sortNumbs.begin(), sortNumbs.end()));
}

int Span::longestSpan()
{
	if (_maxSize <= 1)
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
