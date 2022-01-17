/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:49:54 by dahpark           #+#    #+#             */
/*   Updated: 2022/01/11 20:55:32 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), gateKeeperMode(false) {
	hitpoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap Default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), gateKeeperMode(false) {
	hitpoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap), gateKeeperMode(scavtrap.gateKeeperMode) {
	std::cout << "ScapTrap Copy Constructor called." << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &scavtrap) {
	std::cout << "ScavTrap Assignation operator called." << std::endl;
	if (this == &scavtrap)
		return (*this);
	ClapTrap::operator=(scavtrap);
	gateKeeperMode = scavtrap.gateKeeperMode;
	return (*this);
}

void	ScavTrap::attack(std::string const &target) {
	if (hitpoints == 0) {
		std::cout << "ScavTrap " << name << " is already dead." << std::endl;
		return;
	}
	else if (energyPoints == 0)
		std::cout << "ScavTrap " << name << " ran out of EP." << std::endl;
	else {
		std::cout << "ScavTrap " << name << " attacks " << target << "." << std::endl;
		energyPoints -= 2;
	}
	printStatus();
}

void	ScavTrap::guardGate(void) {
	if (hitpoints == 0)
		std::cout << name << " is already dead." << std::endl;
	else if (gateKeeperMode)
		std::cout << name << " have already entered in Gate Keeper Mode." << std::endl;
	else if (!gateKeeperMode)
		std::cout << name << " entered in Gate Keeper Mode." << std::endl;
}