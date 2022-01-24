/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:19:34 by dahpark           #+#    #+#             */
/*   Updated: 2022/01/24 15:31:25 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP_
#define BRAIN_HPP_

#include <iostream>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &brain);
		~Brain();
		Brain& operator=(const Brain &brain);
};

#endif