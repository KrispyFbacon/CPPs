/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/26 13:44:13 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "Utils.hpp"
#include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	private:
		std::string _type;
		
	public:
		MateriaSource();
		MateriaSource(std::string const& type);
		MateriaSource(const MateriaSource& other);
		virtual ~MateriaSource();
		
		MateriaSource& operator=(const MateriaSource& other);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};
#endif