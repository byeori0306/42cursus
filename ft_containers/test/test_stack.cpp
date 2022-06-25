/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:49:39 by dahpark           #+#    #+#             */
/*   Updated: 2022/06/25 21:47:10 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../test/Test.hpp"
#include "../container/Stack.hpp"

void test_stack(void) {
	std::cout << HIGHLIGHT << "================================= stack test ================================" << RESET << std::endl;
	
	std::stack<int> std_stack;
	ft::stack<int> ft_stack;
	
	// before push()
	print_result("empty() (before push())", std_stack.empty(), ft_stack.empty());
	
	// after push()
	for (int i = 1; i <= 10; i++) {
		std_stack.push(i);
		ft_stack.push(i);
	}

	print_result("size() (after push())", std_stack.size(), ft_stack.size());

	print_result("top() (after push())", std_stack.top(), ft_stack.top());

	print_result("empty() (after push())", std_stack.empty(), ft_stack.empty());

	// after pop()
	std_stack.pop();
	ft_stack.pop();

	print_result("size() (after pop())", std_stack.size(), ft_stack.size());

	print_result("top() (after pop())", std_stack.top(), ft_stack.top());

	// relational operators
	std::stack<int> std_stack2;
	ft::stack<int> ft_stack2;

	std::stack<int> std_stack3;
	ft::stack<int> ft_stack3;

	for (int i = 1; i <= 10; i++) {
		std_stack2.push(i);
		ft_stack2.push(i);
	}

	for (int i = 1; i <= 9; i++) {
		std_stack3.push(i);
		ft_stack3.push(i);
	}
	std_stack3.push(100);
	ft_stack3.push(100);

	print_result("S1 == S2", std_stack == std_stack2, ft_stack == ft_stack2);
	print_result("S1 != S2", std_stack != std_stack2, ft_stack != ft_stack2);
	print_result("S1 < S2", std_stack < std_stack3, ft_stack < ft_stack3);
	print_result("S1 <= S2", std_stack <= std_stack3, ft_stack <= ft_stack3);
	print_result("S1 > S2", std_stack > std_stack3, ft_stack > ft_stack3);
	print_result("S1 >= S2", std_stack >= std_stack3, ft_stack >= ft_stack3);
}