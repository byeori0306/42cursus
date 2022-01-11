/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:18:47 by dahpark           #+#    #+#             */
/*   Updated: 2022/01/11 20:54:32 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {
	ClapTrap A("A");
	ScavTrap B("B");

	A.attack("B");
	B.takeDamage(10);

	B.attack("A");
	A.takeDamage(10);

	B.beRepaired(10);

	B.attack("A");
	A.takeDamage(10);

	B.guardGate();
}