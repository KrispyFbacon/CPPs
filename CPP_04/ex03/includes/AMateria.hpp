/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/19 18:12:28 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "Utils.hpp"
// #include <iostream>
// #include "Color.hpp"
// #include "ICharacter.hpp"

class	AMateria
{
	protected:
		std::string _type;
		
	public:
		AMateria(std::string const& type);
		AMateria(const AMateria& other);
		
		virtual ~AMateria();
		
		AMateria& operator=(const AMateria& other);

		std::string const& getType() const; //Returns the materia type
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		
};
#endif