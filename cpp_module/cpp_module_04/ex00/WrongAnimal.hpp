/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:30:45 by dahpark           #+#    #+#             */
/*   Updated: 2022/01/18 21:00:39 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP_
#define WRONG_ANIMAL_HPP_

#include <iostream>

class WrongAnimal {
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &wrong);
		virtual ~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal &wrong);
		std::string	getType(void) const;
		void	makeSound(void) const;
};

#endif