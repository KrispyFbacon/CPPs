/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:28:27 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/30 11:27:34 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int argc, char* argv[])
{
	int	status;
	
	if (argc != 4)
	{
		std::cout << BOLD_R << "Error " << RST << std::endl;
		std::cout << BOLD_M << "Usage: "
				  << BOLD_Y << argv[0] << " [filename] [s1] [s2]\n" 
				  << RST << std::endl;
		return (1);
	}

	status = sed(argv[1], argv[2], argv[3]);
	return (status);
}