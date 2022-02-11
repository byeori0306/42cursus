/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:18:41 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/11 15:34:27 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hitpoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitpoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap) : name(claptrap.name), hitpoints(claptrap.hitpoints), energyPoints(claptrap.energyPoints), attackDamage(claptrap.attackDamage) {
	std::cout << "Copy Constructor called." << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &claptrap) {
	std::cout << "Assignation operator called." << std::endl;
	if (this == &claptrap)
		return (*this);
	name = claptrap.name;
	hitpoints = claptrap.hitpoints;
	energyPoints = claptrap.energyPoints;
	attackDamage = claptrap.attackDamage;
	return (*this);
}

void	ClapTrap::attack(std::string const &target) {
	if (hitpoints == 0) {
		std::cout << "ClapTrap " << name << " is already dead." << std::endl;
		return;
	}
	else if (energyPoints == 0)
		std::cout << "ClapTrap " << name << " ran out of EP." << std::endl;
	else {
		std::cout << "ClapTrap " << name << " attacks " << target << "." << std::endl;
		energyPoints -= 2;
	}
	printStatus();
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (hitpoints == 0) {
		std::cout << "ClapTrap " << name << " is already dead." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " takes damage. => HP -" << amount << "" << std::endl;

	if (amount > (unsigned)hitpoints)
		hitpoints = 0;
	else
		hitpoints -= amount;
	if (hitpoints == 0)
		std::cout << "ClapTrap " << name << " is dead." << std::endl;
	printStatus();
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (hitpoints == 0) {
		std::cout << "ClapTrap " << name << " is already dead." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " is repaired. => HP +" << amount << "" << std::endl;

	unsigned int result = hitpoints + amount;
	if (result > 100)
		hitpoints = 100;
	else
		hitpoints = result;
	printStatus();
}

void	ClapTrap::printStatus(void) {
	std::cout << "* " << name << "\'s HP : " << hitpoints << std::endl;
	std::cout << "* " << name << "\'s EP : " << energyPoints << std::endl;
	std::cout << "* " << name << "\'s AD : " << attackDamage << std::endl;
}