/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:31:32 by dahpark           #+#    #+#             */
/*   Updated: 2022/01/24 16:35:52 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	const Animal* meta[10];
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	for (int i = 0; i <5; i++)
		meta[i] = new Dog();
	for (int i = 5; i < 10; i++)
		meta[i] = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	j->makeSound();
	i->makeSound();

	for (int i = 0; i < 10; i++)
		delete meta[i];
	delete j;
	delete i;
}