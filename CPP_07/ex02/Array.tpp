/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:20:16 by frbranda          #+#    #+#             */
/*   Updated: 2026/01/15 15:25:44 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _arr(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other) : _arr(new T[other._size]()), _size(other._size)
{
	for (unsigned int i = 0; i < _size; ++i)
		this->_arr[i] = other._arr[i];
}

template <typename T>
Array<T>::~Array() 
{
	delete [] _arr;
}


/* ========================== Overload Operators =========================== */

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		T* newArr = new T[other._size]();
		delete[] this->_arr;
		
		this->_arr = newArr;
		this->_size = other._size;

		for (unsigned int i = 0; i < _size; ++i)
			this->_arr[i] = other._arr[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= this->size())
		throw std::out_of_range("Index is out of range");
	return (_arr[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= this->size())
		throw std::out_of_range("Index is out of range");
	return (_arr[index]);
}


/* ========================== Member Functions =========================== */

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}