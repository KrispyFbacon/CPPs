/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/29 14:56:11 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream> // library for files
#include "Color.hpp"
#include "Error.hpp"

#define	ERROR 1

class	Sed
{
	private:
		
	public:

};

int	sed(const std::string &filename, const std::string &s1, const std::string &s2);

#endif