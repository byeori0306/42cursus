/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:17:48 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/22 16:36:44 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	int		N;
	Zombie	*zombies;

	N = 10;
	zombies = Zombie::zombieHorde(N, "zombie");
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete[] zombies;
}