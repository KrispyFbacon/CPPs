/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:03:23 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/07 11:42:20 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_HPP
# define COLOR_HPP

/**
 * @brief ANSI escape codes for terminal text color formatting.
 * 
 * Usage example:
 * 	std::cout << R << "This is red text." << RST << std::endl;
 * 	std::cout << BOLD_B << "This is bold blue text." << RST << std::endl;
 * 
 * Includes regular and bold color definitions for standard foreground colors.
 * 
 * @warning Always use 'RST' after a color constant to
 *          avoid unintentional styling.
 * 
 * Categories:
 * - RESET: Resets all styles to default.
 * - Regular Colors: BLACK, R (Red), G (Green), Y (Yellow), B (Blue),
 *                   M (Magenta), C (Cyan), W (White).
 * - Bold Colors: BOLD_<COLOR> for bold versions of regular colors.
 */

/* RESET / CLEAR*/
/** @brief Reset all text formatting. */
# define RST	"\033[0m"

/** @brief Clear screen */
# define CLEAR		"\033[2J\033[H"

/* Regular Colors */
/** @brief Regular black text. */
# define BLACK	"\033[0;30m"
/** @brief Regular red text. */
# define R		"\033[0;31m"
/** @brief Regular green text. */
# define G		"\033[0;32m"
/** @brief Regular yellow text. */
# define Y		"\033[0;33m"
/** @brief Regular blue text. */
# define B		"\033[0;34m"
/** @brief Regular magenta text. */
# define M		"\033[0;35m"
/** @brief Regular cyan text. */
# define C		"\033[0;36m"
/** @brief Regular white text. */
# define W		"\033[0;37m"

/* Bold Colors */
/** @brief Bold black text. */
# define BOLD_BLACK	"\033[1;30m"
/** @brief Bold red text. */
# define BOLD_R		"\033[1;31m"
/** @brief Bold green text. */
# define BOLD_G		"\033[1;32m"
/** @brief Bold yellow text. */
# define BOLD_Y		"\033[1;33m"
/** @brief Bold blue text. */
# define BOLD_B		"\033[1;34m"
/** @brief Bold magenta text. */
# define BOLD_M		"\033[1;35m"
/** @brief Bold cyan text. */
# define BOLD_C		"\033[1;36m"
/** @brief Bold white text. */
# define BOLD_W		"\033[1;37m"

/* Background colors */
# define BG_BLACK	"\033[40m"
# define BG_R		"\033[41m"
# define BG_G		"\033[42m"
# define BG_Y		"\033[43m"
# define BG_B		"\033[44m"
# define BG_M		"\033[45m"
# define BG_C		"\033[46m"
# define BG_W		"\033[47m"

/* Bright Foreground */
# define BRIGHT_BLACK	"\033[90m"
# define BRIGHT_R		"\033[91m"
# define BRIGHT_G		"\033[92m"
# define BRIGHT_Y		"\033[93m"
# define BRIGHT_B		"\033[94m"
# define BRIGHT_M		"\033[95m"
# define BRIGHT_C		"\033[96m"
# define BRIGHT_W		"\033[97m"

/* Bright Background */
# define BG_BRIGHT_BLACK	"\033[100m"
# define BG_BRIGHT_R		"\033[101m"
# define BG_BRIGHT_G		"\033[102m"
# define BG_BRIGHT_Y		"\033[103m"
# define BG_BRIGHT_B		"\033[104m"
# define BG_BRIGHT_M		"\033[105m"
# define BG_BRIGHT_C		"\033[106m"
# define BG_BRIGHT_W		"\033[107m"


/** @brief White text, Red background */
# define WR_BG		"\033[1;97;41m"  // bold white + red background


/* CUSTOM COLORS? */
# define RGB(r, g, b)		"\033[38;2;" #r ";" #g ";" #b "m"
# define BG_RGB(r, g, b)	"\033[48;2;" #r ";" #g ";" #b "m"

#endif