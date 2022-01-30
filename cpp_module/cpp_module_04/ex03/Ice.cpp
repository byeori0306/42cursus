/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:40:13 by dahpark           #+#    #+#             */
/*   Updated: 2022/01/30 21:08:54 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ice.hpp"

Ice::Ice(void) : AMateria("ice") {
	std::cout << "Ice default constructor called" <<std::endl;
}

Ice::Ice(const Ice& ice) : AMateria(ice.getType()) {
	std::cout << "Ice copy constructor called." << std::endl;
}

Ice& Ice::operator=(const Ice& ice) {
	std::cout << "Ice assignation operator called." << std::endl;
	if (this == &ice)
		return (*this);
	type = ice.getType();
	return (*this);
}

Ice::~Ice(void) {
	std::cout << "Ice destructor called" <<std::endl;
}

AMateria*	Ice::clone(void) const {
	return (new Ice());
}

void		Ice::use(ICharacter &target) {
	std::cout << "* shoot an ice bolt at " + target.getName() + " *" << std::endl;
}