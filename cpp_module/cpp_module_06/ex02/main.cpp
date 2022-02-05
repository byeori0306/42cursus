/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:48:49 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/05 21:20:08 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void) {
	srand((unsigned int)time(NULL));
	int idx = rand() % 3;
	switch (idx) {
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (NULL);
	}
}

void	identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base& p) {
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception& e) { }
	try {
		B b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception& e) { }
	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception& e) { }
}

int main(void) {
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
}