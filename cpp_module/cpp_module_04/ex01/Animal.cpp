/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:43:18 by dahpark           #+#    #+#             */
/*   Updated: 2022/01/18 20:55:01 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Animal") {
	std::cout << "Animal default constructor called" <<std::endl;
}

Animal::Animal(const Animal &animal) : type(animal.getType()) {
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called" <<std::endl;
}

Animal&	Animal::operator=(const Animal &animal) {
	std::cout << "Animal assignation operator called." << std::endl;
	if (this == &animal)
		return (*this);
	type = animal.getType();
	return (*this);
}

std::string	Animal::getType(void) const {
	return (type);
}

void	Animal::makeSound(void) const {
	std::cout << "I'm an animal. What sound do I make?" <<std::endl;
}