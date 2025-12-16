/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:05:40 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/16 18:40:37 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << BOLD_R << "Error: Most have 1 argument!"
					<< RST << std::endl;
		return 1;
	}
	
	ScalarConverter::convert(argv[1]);
	
	return 0;
}

