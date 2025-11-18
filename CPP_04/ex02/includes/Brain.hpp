/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/18 16:19:12 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include "Color.hpp"

/* Class and identifier colors */
#define CLASS_COLOR	BOLD_Y

class	Brain
{
	protected:
		std::string _ideas[100];
	
	public:
		Brain();
		Brain(const Brain& other);
		
		virtual ~Brain();
		
		Brain& operator=(const Brain& other);

		void setIdea(int index, const std::string& idea);
		const std::string& getIdea(int index) const;
};
#endif