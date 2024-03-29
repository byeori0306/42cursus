/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:26:25 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/26 14:36:11 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_H_
#define HUMAN_B_H_

#include <string>
#include "Weapon.hpp"

class HumanB {
	private:
		std::string	name;
		Weapon		*weapon;
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon &weapon);
		void	attack(void);
};

#endif