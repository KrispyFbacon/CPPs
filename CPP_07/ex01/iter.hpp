/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:13:14 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/19 18:31:02 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

typedef void (*func)(T&);

template <typename T>
void	iter(T* arr, const int len, func f)
{
	for (int i = 0; i < len; ++i)
		f(arr[i]);
}

template <typename T>
void print(const T& src)
{
	std::cout << src << std::endl;
}

#endif