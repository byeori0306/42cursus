/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:18:36 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/02 17:56:54 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : name("default") {
	std::cout << "Character default constructor called" <<std::endl;
	for (int i = 0; i < MAX_SLOT; i++) {
		inventory[i] = NULL;
	}
}

Character::Character(const std::string name) : name(name) {
	std::cout << "Character constructor called" <<std::endl;
	for (int i = 0; i < MAX_SLOT; i++) {
		inventory[i] = NULL;
	}
}

Character::Character(const Character &ch) {
	std::cout << "Character copy constructor called" <<std::endl;
	name = ch.getName();
	for (int i = 0; i < MAX_SLOT; i++) {
		if (inventory[i]) {
			delete inventory[i];
			inventory[i] = NULL;
		}
		if (ch.inventory[i])
			inventory[i] = ch.inventory[i]->clone();
	}
}

Character& Character::operator=(const Character& ch) {
	std::cout << "Character assignation operator called" <<std::endl;
	if (this == &ch)
		return (*this);
	name = ch.getName();
	for (int i = 0; i < MAX_SLOT; i++) {
		if (inventory[i]) {
			delete inventory[i];
			inventory[i] = NULL;
		}
		if (ch.inventory[i])
			inventory[i] = ch.inventory[i]->clone();
	}
	return (*this);
}

Character::~Character(void) {
	std::cout << "Character destructor called" <<std::endl;
	for (int i = 0; i < MAX_SLOT; i++) {
		if (inventory[i]) {
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
}

std::string const & Character::getName() const {
	return (name);
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < MAX_SLOT; i++) {
		if (!inventory[i]) {
			inventory[i] = m;
			break;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx > -1 && idx < MAX_SLOT)
		inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx > -1 && idx < MAX_SLOT && inventory[idx])
		inventory[idx]->use(target);
}