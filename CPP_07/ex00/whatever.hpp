/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:36:33 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/19 15:23:34 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <iomanip>
#include <string>

template <typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


/* ================================ Min/Max ================================ */

template <typename T>
T& min(T& a, T& b)
{
	return (a < b ? a : b);
}

template <typename T>
T& max(T& a, T& b)
{
	return (a > b ? a : b);
}


/* ============================= Const Min/Max ============================= */

template <typename T>
const T& min(const T& a, const T& b)
{
	return (a < b ? a : b);
}

template <typename T>
const T& max(const T& a, const T& b)
{
	return (a > b ? a : b);
}



/* ============================ Class Template ============================= */

// template <typename T>
// class Whatever
// {
// 	public:
// 		static void swap(T& a, T& b)
// 		{
// 			T temp = a;
// 			a = b;
// 			b = temp;
// 		}

// 		static T& min(T& a, T& b)
// 		{
// 			return (a < b ? a : b);
// 		}

// 		static T& max(T& a, T& b)
// 		{
// 			return (a > b ? a : b);
// 		}

// 		static const T& min(const T& a, const T& b)
// 		{
// 			return (a < b ? a : b);
// 		}

// 		static const T& max(const T& a, const T& b)
// 		{
// 			return (a > b ? a : b);
// 		}
// };

#endif