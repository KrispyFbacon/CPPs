/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:20:16 by frbranda          #+#    #+#             */
/*   Updated: 2026/01/14 18:23:35 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _arr(new T[0]()) {} // or _arr(NULL)

template <typename T>
Array<T>::Array(unsigned int i) : _arr(new T[i]()) {}

template <typename T>
Array<T>::Array(const Array& other) : _arr(new T[other.size()]())
{
	for (int i = 0; other._arr[i]; ++i)
		this->_arr[i] = other._arr[i];
}

template <typename T>
Array<T>::~Array() 
{
	delete [] _arr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete [] this->_arr;
		_array = new T[other.size()]();
		for (int i = 0; other._arr[i]; ++i)
			this->_arr[i] = other._arr[i];
	}

	return *this;
}

template <typename T>
unsigned int Array<T>::size(const T& array) const
{
	return (sizeof(array) / sizeof(array[0]);
}