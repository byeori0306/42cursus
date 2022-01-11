/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:18:47 by dahpark           #+#    #+#             */
/*   Updated: 2022/01/11 21:47:12 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	ScavTrap A("A");
	FragTrap B("B");

	B.highFivesGuys();
	
	A.attack("B");
	B.takeDamage(20);

	B.attack("A");
	A.takeDamage(30);

	B.beRepaired(10);

	B.attack("A");
	A.takeDamage(30);

	A.guardGate();	
}