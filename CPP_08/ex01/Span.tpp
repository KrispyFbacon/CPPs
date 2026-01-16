/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:58:50 by frbranda          #+#    #+#             */
/*   Updated: 2026/01/16 18:25:21 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
	size_t range = std::distance(begin, end);
	if (_numbs.size() + range > _maxSize)
		throw SpanFullException();
	
	for (Iterator it = begin; it != end; ++it)
		_numbs.push_back(*it);
}
