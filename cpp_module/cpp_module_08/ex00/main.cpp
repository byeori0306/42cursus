/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:47:49 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/07 13:57:01 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main() {
	std::vector<int> arr;
	
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(3);
	
	int target = 3;
	try {
		std::vector<int>::iterator itr = easyfind(arr, target);
		int idx = distance(arr.begin(), itr);
		std::cout << idx << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}