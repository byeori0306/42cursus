/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:50:50 by dahpark           #+#    #+#             */
/*   Updated: 2022/01/25 16:39:21 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : type("") {
	std::cout << "AMateria default constructor called" <<std::endl;
}

AMateria::AMateria(const AMateria& amateria) : type(amateria.getType()) {
	std::cout << "AMateria copy constructor called." << std::endl;
}

AMateria& AMateria::operator=(const AMateria& amateria) {
	std::cout << "AMateria assignation operator called." << std::endl;
	if (this == &amateria)
		return (*this);
	type = amateria.getType();
	return (*this);
}

AMateria::~AMateria(void) {
	std::cout << "AMateria destructor called" <<std::endl;
}

AMateria::AMateria(std::string const & type) : type(type) {
	std::cout << "AMateria constructor called" <<std::endl;
}

std::string const & AMateria::getType() const {
	return (type);	
};

void	AMateria::use(ICharacter & target) {
	std::cout << target.getName() << " use AMateria" << std::endl;
}