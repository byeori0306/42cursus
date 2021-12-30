/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:18:47 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/30 20:16:21 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
	ClapTrap A("A");
	ClapTrap B("B");

	A.beRepaired(10);
	B.beRepaired(10);

	A.attack("B");
	B.takeDamage(10);

	B.attack("A");
	A.takeDamage(10);

	B.beRepaired(10);

	A.attack("B");
	B.takeDamage(10);

	B.attack("A");
	A.takeDamage(10);
}