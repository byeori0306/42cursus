/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:31:32 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/15 17:39:59 by dahpark          ###   ########seoul.kr  */
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

	Dog a_dog;
	Dog b_dog(a_dog);

	for (int i = 0; i < 10; i++)
		delete meta[i];
	delete j;
	delete i;
}