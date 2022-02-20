/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:41:12 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/20 16:24:33 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void	test_int(void) {
	Array<int> array(5);

	for (unsigned int i = 0; i < 5; i++) {
		array[i] = i;
	}

	for (unsigned int i = 0; i < 5; i++) {
		std::cout << "array : " << array[i] << std::endl;
	}

	Array<int> test(array);

	for (unsigned int i = 0; i < 5; i++) {
		std::cout << "test : "  << test[i] << std::endl;
	}

	try {
		array[2] = 10;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	for (unsigned int i = 0; i < 5; i++) {
		std::cout << "array : " << array[i] << std::endl;
	}

	for (unsigned int i = 0; i < 5; i++) {
		std::cout << "test : "  << test[i] << std::endl;
	}

	try {
		array[10] = 10;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void	test_char(void) {
	Array<char> array(5);
	std::string str = "abcde";

	for (unsigned int i = 0; i < 5; i++) {
		array[i] = str[i];
	}

	for (unsigned int i = 0; i < 5; i++) {
		std::cout << "array : " << array[i] << std::endl;
	}

	Array<char> test(array);
	
	for (unsigned int i = 0; i < 5; i++) {
		std::cout << "test : "  << test[i] << std::endl;
	}

	try {
		array[2] = 'x';
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	for (unsigned int i = 0; i < 5; i++) {
		std::cout << "array : " << array[i] << std::endl;
	}

	for (unsigned int i = 0; i < 5; i++) {
		std::cout << "test : "  << test[i] << std::endl;
	}
}

int main(void) {
	test_int();
	std::cout << std::endl;
	test_char();
}