/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:29:38 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/17 18:15:44 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
}

Serializer::~Serializer() {}

Serializer Serializer::operator=(const Serializer& other)
{
	(void)other;
	return *this;
}


/* ==================================== ==================================== */

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (ptr ? reinterpret_cast<uintptr_t>(ptr) : 0);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (raw ? reinterpret_cast<Data *>(raw) : NULL);
}