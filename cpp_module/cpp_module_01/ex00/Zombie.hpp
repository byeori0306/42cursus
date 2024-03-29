/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:22:34 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/26 14:36:03 by dahpark          ###   ########seoul.kr  */
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
	Zombie*	newZombie(std::string name);
	void	randomChump(std::string name);
};

#endif