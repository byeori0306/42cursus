/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:05:26 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/21 22:29:08 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

void	basic_test() {
	Span sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	one_elem_test() {
	try {
		Span sp = Span(5);

		sp.addNumber(5);
		sp.longestSpan();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	ten_thousand_elem_test(std::vector<int>& array) {
	try {
		Span sp = Span(10001);

		sp.addNumber(array.begin(), array.end());
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	std::vector<int> array;
	for (int i = 1; i <= 10001; i++) {
		array.push_back(i * 2);
	}
	
	basic_test();
	std::cout << std::endl;
	one_elem_test();
	std::cout << std::endl;
	ten_thousand_elem_test(array);
}