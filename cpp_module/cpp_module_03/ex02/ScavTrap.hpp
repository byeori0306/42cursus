/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:49:57 by dahpark           #+#    #+#             */
/*   Updated: 2022/01/11 20:47:16 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP_
#define SCAV_TRAP_HPP_

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:
		bool	gateKeeperMode;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &scavtrap);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap &scavtrap);
		void	attack(std::string const &target);
		void	guardGate(void);
};

#endif