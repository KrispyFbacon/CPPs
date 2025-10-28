/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:28:27 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/28 17:08:30 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

# define RST	"\033[0m"

# define Y		"\033[0;33m"
# define C		"\033[0;36m"

int	main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	
	std::string*	str_ptr = &str;
	std::string&	str_ref = str;

	std::cout << "Address of str:      " << C << &str << RST << std::endl;
	std::cout << "Address in str_ptr:  " << C << str_ptr << RST << std::endl;
	std::cout << "Address of str_ref:  " << C << &str_ref << RST << std::endl;
	
	std::cout << std::endl;
	std::cout << "Value of str:        " << Y << str << RST << std::endl;
	std::cout << "Value via str_ptr:   " << Y << *str_ptr << RST << std::endl;
	std::cout << "Value via str_ref:   " << Y << str_ref << RST << std::endl;
}