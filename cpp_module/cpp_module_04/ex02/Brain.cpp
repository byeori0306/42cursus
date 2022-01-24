/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:19:31 by dahpark           #+#    #+#             */
/*   Updated: 2022/01/24 15:50:48 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain default constructor called" <<std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "idea";
}

Brain::Brain(const Brain &brain) {
	std::cout << "Brain copy constructor called." << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = brain.ideas[i];
	}
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called" <<std::endl;
}

Brain& Brain::operator=(const Brain &brain) {
	std::cout << "Brain assignation operator called." << std::endl;
	if (this == &brain)
		return (*this);
	for (int i = 0; i < 100; i++) {
		ideas[i] = brain.ideas[i];
	}
	return (*this);
}