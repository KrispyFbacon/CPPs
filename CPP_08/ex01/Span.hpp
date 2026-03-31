/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:32:52 by frbranda          #+#    #+#             */
/*   Updated: 2026/01/21 15:12:47 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm> // std::sort
#include <numeric>	// std::adjacent_difference
#include <ctime>	// time, localtime
#include <cstdlib>	// rand, srand

class Span
{
	private:
		std::vector<int> _numbs;
		unsigned int _maxSize;
		
		Span();
		
	public:
		Span(unsigned int N);
		Span(const Span& other);
		~Span();

		Span& operator=(const Span& other);

		void addNumber(int nbr);
		template <typename Iterator>
		void addRange(Iterator begin, Iterator end);
		void addRange(int begin, int end);

		int shortestSpan();
		int longestSpan();

		// exceptions
		class SpanTooLittleException : public std::exception
		{
			const char* what() const throw();
		};

		class SpanFullException : public std::exception
		{
			const char* what() const throw();
		};

};

#include "Span.tpp"

#endif