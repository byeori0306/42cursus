/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:35:23 by dahpark           #+#    #+#             */
/*   Updated: 2022/01/18 20:37:18 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	std::cout << "WrongCat default constructor called" <<std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &cat) {
	std::cout << "WrongCat copy constructor called." << std::endl;
	type = cat.getType();
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" <<std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &cat) {
	std::cout << "WrongCat assignation operator called." << std::endl;
	if (this == &cat)
		return (*this);
	type = cat.getType();
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << "Meow~" <<std::endl;
}