/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:22:18 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/22 15:45:28 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	zombie;
	Zombie	*new_zombie;

	zombie.randomChump("stack");
	new_zombie = zombie.newZombie("heap");
	new_zombie->announce();
	delete new_zombie;
}