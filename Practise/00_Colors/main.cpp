/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:28:27 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/11 12:10:19 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"
#include <iostream>

int main()
{
	// Custom text colors
	std::cout << RGB(255, 0, 0) << "Red text" << RST << std::endl;
	std::cout << RGB(0, 255, 0) << "Green text" << RST << std::endl;
	std::cout << RGB(0, 0, 255) << "Blue text" << RST << std::endl;
	std::cout << std::endl;
	
	// Custom background colors
	std::cout << BG_RGB(0, 225, 255) << "Cyan background" << RST << std::endl;
	std::cout << BG_RGB(255, 0, 255) << "Magenta background" << RST << std::endl;
	std::cout << std::endl;
		
	// Combine text and background
	std::cout << RGB(255, 255, 255) << BG_RGB(0, 0, 0) 
			  << "White on black" << RST << std::endl;

	// Combined text + background
	std::cout << RGB_COMBO(255,255,255, 255,0,0)
			  << "White text on red background" << RST << std::endl;

	std::cout << RGB_COMBO(0,0,0, 255,255,0)
			  << "Black text on yellow background" << RST << std::endl;

	std::cout << RGB_COMBO(0,255,255, 128,0,128)
			  << "Cyan text on purple background" << RST << std::endl;
	std::cout << std::endl;

	// Combined BOLD text + background
	std::cout << RGB_BOLD(255, 0, 0) << "Bold red text" << RST << std::endl;
		
	std::cout << RGB_COMBO_BOLD(255,255,255, 255,0,0)
			  << "Bold white text on red background" << RST << std::endl;
			  
	std::cout << RGB_COMBO_BOLD(0,0,0, 255,255,0)
			  << "Bold black text on yellow background" << RST << std::endl;
		
	return 0;
}
