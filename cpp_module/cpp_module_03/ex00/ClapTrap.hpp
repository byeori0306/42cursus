/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:18:45 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/30 20:11:35 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_H_
#define CLAP_TRAP_H_

#include <iostream>
#include <string>

class ClapTrap {
	private:
		std::string	name;
		int			hitpoints;
		int			energyPoints;
		int			attackDamage;
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &claptrap);
		~ClapTrap();
		ClapTrap& operator=(const ClapTrap &claptrap);
		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	printStatus(void);
		int		getAttackDamage(void);
};

#endif