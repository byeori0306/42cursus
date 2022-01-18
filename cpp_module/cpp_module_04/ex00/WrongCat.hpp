/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:36:31 by dahpark           #+#    #+#             */
/*   Updated: 2022/01/18 21:00:46 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP_
#define WRONG_CAT_HPP_

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(const WrongCat &cat);
		~WrongCat();
		WrongCat& operator=(const WrongCat &cat);
		void	makeSound(void) const;
};

#endif