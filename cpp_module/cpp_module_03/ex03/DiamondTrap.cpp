/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:31:48 by dahpark           #+#    #+#             */
/*   Updated: 2022/01/17 21:52:44 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : name("default") {
	std::cout << "DiamondTrap Default constructor called." << std::endl;
	ClapTrap::name = name + "_clap_name";
}

DiamondTrap::DiamondTrap(std::string name) : name(name) {
	std::cout << "DiamondTrap constructor called." << std::endl;
	ClapTrap::name = name + "_clap_name";
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap) : ClapTrap(diamondtrap), FragTrap(diamondtrap), ScavTrap(diamondtrap) {
	std::cout << "DiamondTrap Copy Constructor called." << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor called." << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const &diamondtrap) {
	std::cout << "DiamondTrap Assignation operator called." << std::endl;
	if (this == &diamondtrap)
		return (*this);
	name = diamondtrap.name;
	ClapTrap::name = diamondtrap.name + "_clap_name";
	hitpoints = diamondtrap.hitpoints;
	energyPoints = diamondtrap.energyPoints;
	attackDamage = diamondtrap.attackDamage;
	return (*this);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "Who Am I? name : " + name + ", clapTrap name: " + ClapTrap::name << std::endl;
}