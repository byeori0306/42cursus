/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:50:53 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/02 18:11:04 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
		std::string type;
	public:
		AMateria();
		AMateria(const AMateria& amateria);
		AMateria& operator=(const AMateria& amateria);
		virtual ~AMateria();
		
		AMateria(std::string const & type);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter & target);
};

#endif