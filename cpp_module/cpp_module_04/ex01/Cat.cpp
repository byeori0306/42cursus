/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:09:35 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/14 16:34:17 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "Cat default constructor called" <<std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &cat) {
	std::cout << "Cat copy constructor called." << std::endl;
	type = cat.getType();
	brain = new Brain();
	*brain = *cat.brain;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" <<std::endl;
	delete brain;
}

Cat& Cat::operator=(const Cat &cat) {
	std::cout << "Cat assignation operator called." << std::endl;
	if (this == &cat)
		return (*this);
	type = cat.getType();
	*brain = *cat.brain;
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Meow~" <<std::endl;
}