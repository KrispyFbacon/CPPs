/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/27 12:58:21 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "Utils.hpp"
#include "ICharacter.hpp"

class ICharacter;

class	AMateria
{
	protected:
		std::string _type;
		ICharacter* _holder;
		
	public:
		AMateria();
		AMateria(std::string const& type);
		AMateria(const AMateria& other);
		virtual ~AMateria();
		
		AMateria& operator=(const AMateria& other);

		std::string const& getType() const; //Returns the materia type
		std::string getColoredType() const;
		ICharacter* getHolder() const;
		
		void setHolder(ICharacter* src);
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		
};
#endif