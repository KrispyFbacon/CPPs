/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:05:40 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/18 14:57:01 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

void showData(const Data& d)
{
	std::cout << "Name:    " << NUM_COLOR << d.name << RST << std::endl;
	std::cout << "Number:  " << NUM_COLOR << d.num << RST << std::endl;
	std::cout << "Status:  " << (d.status ? BOLD_G "true" : BOLD_R "false")
				<< RST << std::endl;
	std::cout << "Address: " << NUM_COLOR << &d << RST << std::endl;
}

int main ()
{
	Data d = {"Bacon", 25, true};

	std::cout << BOLD_C << "=== Original Data ===" << RST << std::endl;
	showData(d);

	
	uintptr_t serializeData = Serializer::serialize(&d);

	std::cout << BOLD_C << "\n=== Serialized Data ===" << RST << std::endl;
	std::cout << "Raw value (dec): " << NUM_COLOR << serializeData
			  << RST << std::endl;
	std::cout << "Raw value (hex): " << NUM_COLOR
			  << std::showbase << std::hex << serializeData
			  << std::noshowbase << std::dec << RST << std::endl;

	Data* d2 = Serializer::deserialize(serializeData);

	std::cout << BOLD_C << "\n=== Deserialized Data ===" << RST << std::endl;
	showData(*d2);
	
	
	*d2 = (Data){"CJ", 26, false};

	d2->name = "CJ";
	d2->num = 26;
	d2->status = false;
	
	std::cout << BOLD_C << "\n\n=== Modified Data (via d2) ===" << RST << std::endl;
	showData(*d2);
	
	std::cout << BOLD_C << "\n=== Original Data (d) After Modification ===" << RST << std::endl;
	showData(d);
	
	return 0;
}


