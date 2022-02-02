/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 23:23:07 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/02 18:05:37 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

#define MAX_SRC 4

class MateriaSource : public IMateriaSource {
	private:
		AMateria *src[MAX_SRC];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &ms);
		MateriaSource& operator=(const MateriaSource& ms);
		virtual ~MateriaSource();

		void learnMateria(AMateria *materia);
		AMateria* createMateria(std::string const & type);
};

#endif