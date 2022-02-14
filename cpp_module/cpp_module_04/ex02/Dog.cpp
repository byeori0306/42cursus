/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:21:09 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/14 16:33:23 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "Dog default constructor called" <<std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &dog) {
	std::cout << "Dog copy constructor called." << std::endl;
	type = dog.getType();
	brain = new Brain();
	*brain = *dog.brain;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" <<std::endl;
	delete brain;
}

Dog& Dog::operator=(const Dog &dog) {
	std::cout << "Dog assignation operator called." << std::endl;
	if (this == &dog)
		return (*this);
	type = dog.getType();
	*brain = *dog.brain;
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Bow wow!" <<std::endl;
}