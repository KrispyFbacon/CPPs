/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:36:33 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/18 18:35:23 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include "Utils.hpp"

template <typename T>
class Whatever
{
	public:
		static void swap(T& a, T& b)
		{
			T temp = a;
			a = b;
			b = temp;
		}

		static T& min(T& a, T& b)
		{
			return (a < b ? a : b);
		}

		static T& max(T& a, T& b)
		{
			return (a > b ? a : b);
		}

		static const T& min(const T& a, const T& b)
		{
			return (a < b ? a : b);
		}

		static const T& max(const T& a, const T& b)
		{
			return (a > b ? a : b);
		}
};

#endif