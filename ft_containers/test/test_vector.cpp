/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_iterator.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:47:07 by dahpark           #+#    #+#             */
/*   Updated: 2022/06/20 16:00:59 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Test.hpp"
#include "../Vector.hpp"
#include "../VectorIterator.hpp"
#include <vector>

void test_vector(void) {
	std::cout << HIGHLIGHT << "================================= vector test ================================" << RESET << std::endl;

	std::vector<int> stl_v;
	ft::vector<int> ft_v;

	// empty()
	print_result<bool>("empty()", stl_v.empty(), ft_v.empty());

	// push_back()
	for (int i = 10; i <= 100; i += 10) {
		stl_v.push_back(i);
		ft_v.push_back(i);
	}	
	print_vector_result("push_back()", stl_v, ft_v);

	// pop_back()
	stl_v.pop_back();
	ft_v.pop_back();
	print_vector_result("pop_back()", stl_v, ft_v);

	// fill constructor
	std::vector<int> fill_stl_v(10, 100);
	ft::vector<int> fill_ft_v(10, 100);
	print_vector_result("fill constructor", fill_stl_v, fill_ft_v);

	// range constructor
	std::vector<int> range_stl_v(stl_v.begin(), stl_v.end());
	ft::vector<int> range_ft_v(ft_v.begin(), ft_v.end());
	print_vector_result("range constructor", range_stl_v, range_ft_v);

	// copy constructor
	std::vector<int> copy_stl_v(stl_v);
	ft::vector<int> copy_ft_v(ft_v);
	print_vector_result("copy constructor", copy_stl_v, copy_ft_v);

	// assignment operator overload
	std::vector<int> tmp_stl_v = stl_v;
	ft::vector<int> tmp_ft_v = ft_v;
	print_vector_result("assignment operator overload", tmp_stl_v, tmp_ft_v);

	// rbegin() & rend()
	std::string stl_res;
	std::string ft_res;
	for (std::vector<int>::reverse_iterator iter = stl_v.rbegin(); iter != stl_v.rend(); iter++)
		stl_res += (std::to_string(*iter) + " ");
	for (ft::vector<int>::reverse_iterator iter = ft_v.rbegin(); iter != ft_v.rend(); iter++)
		ft_res += (std::to_string(*iter) + " ");
	print_result<std::string>("rbegin() & rend()", stl_res, ft_res);
	
	// size()
	print_result<int>("size()", int(stl_v.size()), int(ft_v.size()));

	// resize() (n > v.size())
	stl_v.resize(13, 130);
	ft_v.resize(13, 130);
	print_result<int>("resize (n > v.size())", int(stl_v.size()), int(ft_v.size()));
	
	// resize() (n < v.size())
	stl_v.resize(10);
	ft_v.resize(10);
	print_result<int>("resize (n < v.size())", int(stl_v.size()), int(ft_v.size()));

	// Element access
	print_result<int>("[] operator overload", stl_v[5], ft_v[5]);

	// at()
	print_result<int>("at()", stl_v.at(5), ft_v.at(5));

	// at() (exception)
	std::cout << YELLOW << "----- at() (exception)" << RESET << std::endl;
	try {
		stl_v.at(100);
	} catch (std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		ft_v.at(100);
	} catch (std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}

	// front()
	print_result<int>("front()", stl_v.front(), ft_v.front());

	// back()
	print_result<int>("back()", stl_v.back(), ft_v.back());

	// assign() (fill)
	stl_v.assign(3, 130);
	ft_v.assign(3, 130);
	print_vector_result("assign() (fill)", stl_v, ft_v);

	// assign() (range)
	std::vector<int> stl_v2;
	ft::vector<int> ft_v2;
	for (int i = 100; i <= 200; i += 10) {
		stl_v2.push_back(i);
		ft_v2.push_back(i);
	}
	stl_v.assign(stl_v2.begin(), stl_v2.end());
	ft_v.assign(ft_v2.begin(), ft_v2.end());
	print_vector_result("assign() (range)", stl_v, ft_v);

	// insert() (single element)
	stl_v.insert(stl_v.begin() + 3, 300);
	ft_v.insert(ft_v.begin() + 3, 300);
	print_vector_result("insert() (single element)", stl_v, ft_v);

	// insert() (fill)
	stl_v.insert(stl_v.begin() + 5, 5, 500);
	ft_v.insert(ft_v.begin() + 5, 5, 500);
	print_vector_result("insert() (fill)", stl_v, ft_v);

	// insert() (range)
	stl_v.insert(stl_v.begin() + 3, stl_v2.begin(), stl_v2.end());
	ft_v.insert(ft_v.begin() + 3, ft_v2.begin(), ft_v2.end());
	print_vector_result("insert() (range)", stl_v, ft_v);
	
	// erase() (single element)
	stl_v.erase(stl_v.begin() + 3);
	ft_v.erase(ft_v.begin() + 3);
	print_vector_result("erase() (single element)", stl_v, ft_v);

	// erase() (range)
	stl_v.erase(stl_v.begin() + 12, stl_v.end());
	ft_v.erase(ft_v.begin() + 12, ft_v.end());
	print_vector_result("erase() (range)", stl_v, ft_v);

	// swap()
	std::vector<int> stl_v_1(3, 100);
	std::vector<int> stl_v_2(6, 200);
	ft::vector<int> ft_v_1(3, 100);
	ft::vector<int> ft_v_2(6, 200);
	
	std::cout << YELLOW << "----- swap()" << RESET << std::endl;
	std::cout << BLUE << "STL_1 (before swap()): " << RESET;
	for (std::vector<int>::iterator iter = stl_v_1.begin(); iter != stl_v_1.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
	std::cout << BLUE << "STL_2 (before swap()): " << RESET;
	for (std::vector<int>::iterator iter = stl_v_2.begin(); iter != stl_v_2.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
	std::cout << MAGENTA << "ft_1 (before swap()): " << RESET;
	for (ft::vector<int>::iterator iter = ft_v_1.begin(); iter != ft_v_1.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
	std::cout << MAGENTA << "ft_2 (before swap()): " << RESET;
	for (ft::vector<int>::iterator iter = ft_v_2.begin(); iter != ft_v_2.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
	
	stl_v_1.swap(stl_v_2);
	ft_v_1.swap(ft_v_2);
	
	std::cout << BLUE << "STL_1 (after swap()): " << RESET;
	for (std::vector<int>::iterator iter = stl_v_1.begin(); iter != stl_v_1.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
	std::cout << BLUE << "STL_2 (after swap()): " << RESET;
	for (std::vector<int>::iterator iter = stl_v_2.begin(); iter != stl_v_2.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
	std::cout << MAGENTA << "ft_1 (after swap()): " << RESET;
	for (ft::vector<int>::iterator iter = ft_v_1.begin(); iter != ft_v_1.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
	std::cout << MAGENTA << "ft_2 (after swap()): " << RESET;
	for (ft::vector<int>::iterator iter = ft_v_2.begin(); iter != ft_v_2.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

void test_vector_iterator(void) {
	// std::vector<int>::iterator iter = stl_v.begin();

	// ++iter;
	// std::cout << *iter << std::endl;
	
	// iter++;
	// std::cout << *iter << std::endl;

	// *iter++;
	// std::cout << *iter << std::endl;

	// --iter;
	// std::cout << *iter << std::endl;
	
	// iter--;
	// std::cout << *iter << std::endl;

	// *iter--;
	// std::cout << *iter << std::endl;

	// iter = v.begin() + 3;
	// std::cout << *iter << std::endl;

	// iter = 3 + v.begin();
	// std::cout << *iter << std::endl;

	// iter = v.end() - 3;
	// std::cout << *iter << std::endl;

	// iter += 2;
	// std::cout << *iter << std::endl;

	// iter -= 2;
	// std::cout << *iter << std::endl;

	// iter = v.begin();
	// std::cout << iter[5] << std::endl;

	// *iter = 101;
	// std::cout << *iter << std::endl;

	// std::vector<int>::iterator a = stl_v.begin() + 3;
	// std::vector<int>::iterator b = stl_v.begin() + 6;
	// *a = 30;
	// *b = 30;
	// std::cout << *b << std::endl;
	// std::cout << (a == b) << std::endl;
	// std::cout << (a != b) << std::endl;
	// std::cout << (a < b) << std::endl;
	// std::cout << (a > b) << std::endl;
	// std::cout << (a <= b) << std::endl;
	// std::cout << (a >= b) << std::endl;
	// std::cout << (b - a) << std::endl;

	// std::vector<int>::iterator c(a);
	// std::cout << *c << std::endl;
}