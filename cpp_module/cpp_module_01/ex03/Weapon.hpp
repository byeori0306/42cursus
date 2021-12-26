/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:14:37 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/26 14:36:14 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H_
#define WEAPON_H_

#include <iostream>

class Weapon {
	private:
		std::string type;
	public:
		Weapon(std::string type);
		void	setType(const std::string &s);
		const std::string	&getType(void);
};

#endif