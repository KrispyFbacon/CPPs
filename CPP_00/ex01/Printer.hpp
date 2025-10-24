/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 09:47:05 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/24 13:37:58 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_HPP
# define PRINTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include "Color.hpp"


/**
 * @brief Optional screen clear macro.
 * 	Set CLEAR_T to 1 to enable clearing between user inputs.
 */
#define CLEAR_T 1
#if CLEAR_T
	#define CLEAR_() std::cout <<  CLEAR
#else
	#define CLEAR_()
#endif
	
/**
 * @brief Handles all user-facing messages, errors, and prompts.
 * 
 * All methods are static, no need to instantiate Printer.
 * Example:
 * 	Printer::prompt();
 * 	Printer::boom();
 */
class Printer
{
	public:
		static void prompt(const std::string &prompt);
		
		//erros
		static void invalidCommand();
		static void boom();
		static void empty();

		//add
		static void added();
		
		//search
		static void startTable();

		//exit
		static void exit();
};

#endif
