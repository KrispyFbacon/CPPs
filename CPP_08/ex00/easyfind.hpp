/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:47:22 by frbranda          #+#    #+#             */
/*   Updated: 2026/01/16 13:06:49 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

// Containers
#include <vector>
#include <list>
#include <deque>
#include <set>


template <typename T>
typename T::iterator	easyfind(T& container, int target);

template <typename T>
typename T::const_iterator	easyfind(const T& container, int target);

#include "easyfind.tpp"

#endif