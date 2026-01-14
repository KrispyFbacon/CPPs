/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:13:14 by frbranda          #+#    #+#             */
/*   Updated: 2026/01/14 15:28:26 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void	iter(T* arr, const int len, void (*const f)(T&))
{
	if (!arr || !f)
		return;
	for (int i = 0; i < len; ++i)
		f(arr[i]);
}

template <typename T>
void	iter(const T* arr, const int len, void (*const f)(const T&))
{
	if (!arr || !f)
		return;
	for (int i = 0; i < len; ++i)
		f(arr[i]);
}

template <typename T, typename F>
void	iter2(T* arr, const int len, F f)
{
	if (!arr || !f)
		return;
	std::cout << "Array Length: " << len << std::endl;
	for (int i = 0; i < len; ++i)
		f(arr[i]);
}

template <typename T>
void print(const T& src)
{
	std::cout << src << std::endl;
}

template <typename T>
void increment(T& e)
{
	e++;
}

#endif