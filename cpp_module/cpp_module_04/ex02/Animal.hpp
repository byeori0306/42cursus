/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:46:26 by dahpark           #+#    #+#             */
/*   Updated: 2022/01/24 16:33:52 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

#include <iostream>

class Animal {
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal &animal);
		virtual ~Animal();
		Animal& operator=(const Animal &animal);
		std::string	getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif