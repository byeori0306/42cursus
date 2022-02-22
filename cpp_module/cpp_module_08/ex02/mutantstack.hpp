/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:58:25 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/22 16:39:25 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP_
#define MUTANTSTACK_HPP_

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack() : std::stack<T>() { }
		MutantStack(const MutantStack& ms) : std::stack<T>(ms) { }
		MutantStack& operator=(const MutantStack& ms) {
			if (this == &ms)
				return (*this);
			this->c = ms.c;
			return (*this);
		}
		~MutantStack() { }

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() {
			return (this->c.begin());
		}
		iterator end() {
			return (this->c.end());
		}
};

#endif