/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:26:38 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/06 14:37:28 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void) {
	std::string str_arr[3] = {"happy", "new", "year"};
	iter(str_arr, 3, print);

	std::cout << std::endl;

	int int_arr[3] = {1, 2, 3};
	iter(int_arr, 3, print);
}