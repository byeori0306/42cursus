/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:18:47 by dahpark           #+#    #+#             */
/*   Updated: 2022/01/17 21:52:09 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
	FragTrap A("A");
	DiamondTrap B("B");

	A.highFivesGuys();
	B.highFivesGuys();
	
	A.attack("B");
	B.takeDamage(20);

	B.attack("A");
	A.takeDamage(30);

	B.beRepaired(10);
	
	B.whoAmI();
	B.guardGate();
}