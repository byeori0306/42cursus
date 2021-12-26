/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:17:58 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/26 14:36:06 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include <iostream>
#include <string>

class Zombie {
private:
	std::string name;
public:
	~Zombie();
	void	announce(void);
	static Zombie* zombieHorde(int N, std::string name);
};

#endif