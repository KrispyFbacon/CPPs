/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:34 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/20 17:40:07 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class	Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure& other);
		
		virtual ~Cure();
		
		Cure& operator=(const Cure& other);

		AMateria* clone() const;
		void tempUse(const std::string& target) const;
		//void use(ICharacter& target);
};
#endif