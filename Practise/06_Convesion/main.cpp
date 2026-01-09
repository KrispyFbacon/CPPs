/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:24:12 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/16 11:36:01 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>   // for fixed and setprecision

int main()
{
	int num1 = 5;
	int num2 = 2;
	double sum = static_cast<double>(num1) / num2;

	std::cout << sum << std::endl; // 2.5
	std::cout << std::setprecision(1) << sum << std::endl; // 2
	//std::cout << std::fixed << sum << std::endl; // 2.5
	std::cout << std::fixed << std::setprecision(1) << sum << std::endl; // 2.5
	std::cout << std::setprecision(1) << sum << std::endl; // 2.5?
	return 0;
}