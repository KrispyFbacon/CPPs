/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:02:52 by frbranda          #+#    #+#             */
/*   Updated: 2026/01/15 15:20:20 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept> // std::out_of_range
#include <ctime>	// time, localtime
#include <cstdlib>	// rand, srand
#include "Color.hpp"

template <typename T>
class Array
{
	private:
		T* _arr;
		unsigned int _size;
		
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		~Array();

		Array& operator=(const Array& other);

		T& operator[](unsigned int index); // modifiable reference
		const T& operator[](unsigned int index) const; // const reference
		
		unsigned int size() const;
};

#include "Array.tpp"

#endif