/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:40:29 by frbranda          #+#    #+#             */
/*   Updated: 2026/06/09 14:20:51 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <cstdlib>
#include <stdexcept>
#include <sys/time.h>

// Containers
#include <vector>
#include <deque>

double	getTime();

template <typename T>
void printContainer(const T& container);

#include "Utils.tpp"

#endif