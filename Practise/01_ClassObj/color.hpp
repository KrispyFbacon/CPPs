/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:03:23 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/16 14:09:27 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_HPP
# define COLOR_HPP

/**
 * @brief ANSI escape codes for terminal text color formatting.
 * 
 * Usage:
 * 		printf(R "This is red text." RESET);
 * 		printf(B "This is blue text.\n" RESET);
 * 
 * Includes regular and bold color definitions for standard foreground colors.
 * 
 * @warning Always use RESET after a color macro to
 * 			avoid unintentional styling.
 * 
 * Categories:
 * - RESET: Resets all styles to default.
 * - Regular Colors: BLACK, R (Red), G (Green), Y (Yellow), B (Blue),
 * 					 M (Magenta), C (Cyan), W (White).
 * - Bold Colors: BOLD_<COLOR> for bold versions of regular colors.
 */

/* RESET*/
/** @brief Reset all text formatting. */
# define RST	"\033[0m"

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


#endif