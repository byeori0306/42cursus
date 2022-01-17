/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:15:37 by dahpark           #+#    #+#             */
/*   Updated: 2022/01/17 21:44:34 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	hitpoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap Default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	hitpoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragtrap) : ClapTrap(fragtrap) {
	std::cout << "FragTrap Copy Constructor called." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called." << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &fragtrap) {
	std::cout << "Fragtrap Assignation operator called." << std::endl;
	if (this == &fragtrap)
		return (*this);
	ClapTrap::operator=(fragtrap);
	return (*this);
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "Let's high five!" << std::endl;
}