/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:18:38 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/02 18:02:58 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <iostream>
#include "ICharacter.hpp"

#define MAX_SLOT 4

class Character : public ICharacter {
	private:
		AMateria *inventory[MAX_SLOT];
		std::string	name;
	public:
		Character();
		Character(const std::string name);
		Character(const Character &ch);
		Character& operator=(const Character& ch);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif