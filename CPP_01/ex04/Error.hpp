/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 09:47:05 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/29 14:56:19 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HPP
# define ERROR_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include "Color.hpp"

class Error
{
	public:
		//error
		static void error(const std::string &error);

		//file
		static void open(const std::string &filename);
};

#endif
