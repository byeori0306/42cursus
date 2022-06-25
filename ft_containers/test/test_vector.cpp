/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:47:07 by dahpark           #+#    #+#             */
/*   Updated: 2022/06/25 20:48:10 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Test.hpp"
#include "../container/Vector.hpp"
#include "../container/VectorIterator.hpp"
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
	print_vector_result<int>("resize (n > v.size())", stl_v, ft_v);
	
	// resize() (n < v.size())
	stl_v.resize(9, 130);
	ft_v.resize(9, 130);
	print_result<int>("resize (n < v.size())", int(stl_v.size()), int(ft_v.size()));
	print_vector_result<int>("resize (n < v.size())", stl_v, ft_v);

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

	// relational operators
	std::vector<int> std_v1;
	std::vector<int> std_v2_1;
	std::vector<int> std_v2_2;

	ft::vector<int> ft_v1;
	ft::vector<int> ft_v2_1;
	ft::vector<int> ft_v2_2;

	for (int i = 10; i < 100; i++) {
		std_v1.push_back(i);
		std_v2_1.push_back(i);
		std_v2_2.push_back(i);
		ft_v1.push_back(i);
		ft_v2_1.push_back(i);
		ft_v2_2.push_back(i);
	}

	std_v2_2[5] = 90;
	ft_v2_2[5] = 90;

	std::cout << YELLOW << "----- V1 == V2 " << RESET << std::endl;
	std::cout << BLUE << "STL: " << RESET;
	std::cout << (std_v1 == std_v2_1) << std::endl; 
	std::cout << MAGENTA << "ft: " << RESET;
	std::cout << (ft_v1 == ft_v2_1) << std::endl; 

	std::cout << YELLOW << "----- V1 != V2 " << RESET << std::endl;
	std::cout << BLUE << "STL: " << RESET;
	std::cout << (std_v1 != std_v2_1) << std::endl; 
	std::cout << MAGENTA << "ft: " << RESET;
	std::cout << (ft_v1 != ft_v2_1) << std::endl;

	std::cout << YELLOW << "----- V1 < V2 " << RESET << std::endl;
	std::cout << BLUE << "STL: " << RESET;
	std::cout << (std_v1 < std_v2_2) << std::endl; 
	std::cout << MAGENTA << "ft: " << RESET;
	std::cout << (ft_v1 < ft_v2_2) << std::endl;

	std::cout << YELLOW << "----- V1 <= V2 " << RESET << std::endl;
	std::cout << BLUE << "STL: " << RESET;
	std::cout << (std_v1 <= std_v2_2) << std::endl; 
	std::cout << MAGENTA << "ft: " << RESET;
	std::cout << (ft_v1 <= ft_v2_2) << std::endl;

	std::cout << YELLOW << "----- V1 > V2 " << RESET << std::endl;
	std::cout << BLUE << "STL: " << RESET;
	std::cout << (std_v1 > std_v2_2) << std::endl; 
	std::cout << MAGENTA << "ft: " << RESET;
	std::cout << (ft_v1 > ft_v2_2) << std::endl;

	std::cout << YELLOW << "----- V1 >= V2 " << RESET << std::endl;
	std::cout << BLUE << "STL: " << RESET;
	std::cout << (std_v1 >= std_v2_2) << std::endl; 
	std::cout << MAGENTA << "ft: " << RESET;
	std::cout << (ft_v1 >= ft_v2_2) << std::endl;
}

void test_vector_iterator(void) {
	std::cout << HIGHLIGHT << "============================ vector iterator test ============================" << RESET << std::endl;
	std::vector<int> stl_v;
	ft::vector<int> ft_v;

	for (int i = 10; i <= 100; i += 10) {
		stl_v.push_back(i);
		ft_v.push_back(i);
	}

	std::vector<int>::iterator stl_iter = stl_v.begin();
	ft::vector<int>::iterator ft_iter = ft_v.begin();

	print_result("++iter", *(++stl_iter), *(++ft_iter));
	print_result("iter++", *(stl_iter++), *(ft_iter++));
	print_result("--iter", *(--stl_iter), *(--ft_iter));
	print_result("iter--", *(stl_iter--), *(ft_iter--));

	stl_iter = stl_v.begin();
	ft_iter = ft_v.begin();
	print_result("iter + 3", *(stl_iter + 3), *(ft_iter + 3));
	stl_iter = stl_v.end();
	ft_iter = ft_v.end();
	print_result("iter - 3", *(stl_iter - 3), *(ft_iter - 3));

	stl_iter = stl_v.begin();
	ft_iter = ft_v.begin();
	stl_iter += 2;
	ft_iter += 2;
	print_result("iter += 2", *stl_iter, *ft_iter);

	stl_iter -= 2;
	ft_iter -= 2;
	print_result("iter -= 2", *stl_iter, *ft_iter);

	print_result("iter[3]", stl_iter[3], ft_iter[3]);

	*stl_iter = 101;
	*ft_iter = 101;
	print_result("*iter = 101", *stl_iter, *ft_iter);


	std::vector<int>::iterator stl_a = stl_v.begin() + 3;
	std::vector<int>::iterator stl_b = stl_v.begin() + 6;

	ft::vector<int>::iterator ft_a = ft_v.begin() + 3;
	ft::vector<int>::iterator ft_b = ft_v.begin() + 6;
	
	print_result("iter1 == iter2", (stl_a == stl_b), (ft_a == ft_b));
	print_result("iter1 != iter2", (stl_a != stl_b), (ft_a != ft_b));
	print_result("iter1 < iter2", (stl_a < stl_b), (ft_a < ft_b));
	print_result("iter1 > iter2", (stl_a > stl_b), (ft_a > ft_b));
	print_result("iter1 < iter2", (stl_a <= stl_b), (ft_a <= ft_b));
	print_result("iter1 > iter2", (stl_a >= stl_b), (ft_a >= ft_b));
	print_result("iter2 - iter1", (stl_b - stl_a), (ft_b - ft_a));

	std::vector<int>::iterator stl_c(stl_iter);
	ft::vector<int>::iterator ft_c(ft_iter);
	print_result("copy assignment", *stl_c, *ft_c);

	// const iterator
	// std::vector<int>::const_iterator stl_citer = stl_v.begin();
	// ft::vector<int>::const_iterator ft_citer = ft_v.begin();

	// *(stl_citer) = 5;
	// *(ft_citer) = 5;
}

void test_reverse_iterator_with_vector(void) {
	std::cout << HIGHLIGHT << "======================= reverse iterator test with vector ======================" << RESET << std::endl;
	std::vector<int> stl_v;
	ft::vector<int> ft_v;

	for (int i = 10; i <= 100; i += 10) {
		stl_v.push_back(i);
		ft_v.push_back(i);
	}

	std::vector<int>::reverse_iterator stl_iter = stl_v.rbegin();
	ft::vector<int>::reverse_iterator ft_iter = ft_v.rbegin();

	print_result("++iter", *(++stl_iter), *(++ft_iter));
	print_result("iter++", *(stl_iter++), *(ft_iter++));
	print_result("--iter", *(--stl_iter), *(--ft_iter));
	print_result("iter--", *(stl_iter--), *(ft_iter--));

	stl_iter = stl_v.rbegin();
	ft_iter = ft_v.rbegin();
	print_result("iter + 3", *(stl_iter + 3), *(ft_iter + 3));
	stl_iter = stl_v.rend();
	ft_iter = ft_v.rend();
	print_result("iter - 3", *(stl_iter - 3), *(ft_iter - 3));

	stl_iter = stl_v.rbegin();
	ft_iter = ft_v.rbegin();
	stl_iter += 2;
	ft_iter += 2;
	print_result("iter += 2", *stl_iter, *ft_iter);

	stl_iter -= 2;
	ft_iter -= 2;
	print_result("iter -= 2", *stl_iter, *ft_iter);

	print_result("iter[3]", stl_iter[3], ft_iter[3]);

	*stl_iter = 101;
	*ft_iter = 101;
	print_result("*iter = 101", *stl_iter, *ft_iter);

	std::vector<int>::reverse_iterator stl_a = stl_v.rbegin() + 3;
	std::vector<int>::reverse_iterator stl_b = stl_v.rbegin() + 6;

	ft::vector<int>::reverse_iterator ft_a = ft_v.rbegin() + 3;
	ft::vector<int>::reverse_iterator ft_b = ft_v.rbegin() + 6;
	
	print_result("iter1 == iter2", (stl_a == stl_b), (ft_a == ft_b));
	print_result("iter1 != iter2", (stl_a != stl_b), (ft_a != ft_b));
	print_result("iter1 < iter2", (stl_a < stl_b), (ft_a < ft_b));
	print_result("iter1 > iter2", (stl_a > stl_b), (ft_a > ft_b));
	print_result("iter1 < iter2", (stl_a <= stl_b), (ft_a <= ft_b));
	print_result("iter1 > iter2", (stl_a >= stl_b), (ft_a >= ft_b));
	print_result("iter2 - iter1", (stl_b - stl_a), (ft_b - ft_a));

	std::vector<int>::reverse_iterator stl_c(stl_iter);
	ft::vector<int>::reverse_iterator ft_c(ft_iter);
	print_result("copy assignment", *stl_c, *ft_c);
}