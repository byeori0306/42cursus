/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 23:23:03 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/02 19:52:56 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	std::cout << "MateriaSource default constructor called" <<std::endl;
	for (int i = 0; i < MAX_SRC; i++) {
		src[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& ms) {
	std::cout << "MateriaSource copy constructor called" <<std::endl;
	for (int i = 0; i < MAX_SRC; i++) {
		if (src[i]) {
			delete src[i];
			src[i] = NULL;
		}
		if (ms.src[i])
			src[i] = ms.src[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& ms) {
	std::cout << "MateriaSource assignation operator called" <<std::endl;
	if (this == &ms)
		return (*this);
	for (int i = 0; i < MAX_SRC; i++) {
		if (src[i]) {
			delete src[i];
			src[i] = NULL;
		}
		if (ms.src[i])
			src[i] = ms.src[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource(void) {
	std::cout << "MateriaSource destructor called" <<std::endl;
	for (int i = 0; i < MAX_SRC; i++) {
		if (src[i]) {
			delete src[i];
			src[i] = NULL;
		}
	}
}

void	MateriaSource::learnMateria(AMateria *materia) {
	for (int i = 0; i < MAX_SRC; i++) {
		if (!src[i]) {
			src[i] = materia;
			break;
		}		
	}
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < MAX_SRC; i++) {
		if (src[i] && src[i]->getType() == type) {
			return (src[i]->clone());
		}
	}
	return (0);
}