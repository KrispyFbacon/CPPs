/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:02:52 by frbranda          #+#    #+#             */
/*   Updated: 2026/01/14 18:14:17 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T* _arr;
	public:
		Array();
		Array(unsigned int n); //int * a = new int(); then dispaly *a
		Array(const Array& other);
		~Array();

		Array& operator=(const Array& other);

		T& operator[](unsigned int index);
		const T& operator[]unsigned int index() const;
		//std::exceptions
		
		unsigned int size(const T& array) const; // number of elements
};

#endif