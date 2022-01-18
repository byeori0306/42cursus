/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:32:13 by dahpark           #+#    #+#             */
/*   Updated: 2022/01/18 20:34:59 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" <<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrong) : type(wrong.getType()) {
	std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" <<std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &wrong) {
	std::cout << "WrongAnimal assignation operator called." << std::endl;
	if (this == &wrong)
		return (*this);
	type = wrong.getType();
	return (*this);
}

std::string	WrongAnimal::getType(void) const {
	return (type);
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "I'm an WrongAnimal. What sound do I make?" <<std::endl;
}