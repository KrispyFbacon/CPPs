/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:30:56 by frbranda          #+#    #+#             */
/*   Updated: 2026/06/01 12:13:44 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <string>

// ── FATAL ERRORS ───────────────────────────────────────────────────────

class BitcoinException : public std::exception
{
	private:
		std::string _message;
		
	public:
		explicit BitcoinException(const std::string& msg) : _message(msg) {}
		virtual ~BitcoinException() throw() {}
		
		const char* what() const throw() { return _message.c_str(); }
};

#endif