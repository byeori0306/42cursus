/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:09:15 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/02 18:12:04 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
	std::cout << "Cure default constructor called" <<std::endl;
}

Cure::Cure(const Cure& cure) : AMateria(cure.getType()) {
	std::cout << "Cure copy constructor called." << std::endl;
}

Cure& Cure::operator=(const Cure& cure) {
	std::cout << "Cure assignation operator called." << std::endl;
	if (this == &cure)
		return (*this);
	type = cure.getType();
	return (*this);
}

Cure::~Cure(void) {
	std::cout << "Cure destructor called" <<std::endl;
}

AMateria*	Cure::clone(void) const {
	return (new Cure());
}

void		Cure::use(ICharacter &target) {
	std::cout << "* heals " + target.getName() + "'s wounds *" << std::endl;
}