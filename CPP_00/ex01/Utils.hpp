/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:52:09 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/24 18:58:23 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <cctype>
# include <algorithm>

std::string trim(const std::string &str);
bool isValidName(const std::string &str);
bool isValidNumber(const std::string &str);

#endif