/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:40:29 by frbranda          #+#    #+#             */
/*   Updated: 2026/07/18 17:44:39 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <algorithm>
#include <cstdlib>
#include <stdexcept>
#include <iomanip>
#include <sys/time.h>

// Containers
#include <vector>
#include <deque>

const bool SHORT_PRINT = false;
const int MAX_PRINT = 10;

double	getTime();

template <typename T>
void printContainer(const T& container);

#include "Utils.tpp"

#endif