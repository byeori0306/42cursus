/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 23:06:07 by dahpark           #+#    #+#             */
/*   Updated: 2022/06/25 21:35:23 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP_
#define TEST_HPP_

#include <iostream>
#include <vector>
#include <stack>
#include "../container/Vector.hpp"
#include "../container/VectorIterator.hpp"
#include "../container/Stack.hpp"

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define HIGHLIGHT "\033[43m"

template <class T>
void print_result(std::string test, const T& a, const T& b) {
	std::cout << YELLOW << "----- ";
	std::cout << test << RESET << std::endl;
	std::cout << BLUE << "STL: " << RESET << a << std::endl;
	std::cout << MAGENTA << "ft: " << RESET << b << std::endl;
	if (a == b)
		std::cout << "Result: " << GREEN << "OK" << RESET << std::endl;
	else
		std::cout << "Result: " << RED << "KO" << RESET << std::endl;
}

void test_vector(void);
void test_vector_iterator(void);
void test_reverse_iterator_with_vector(void);
void test_stack(void);

#endif