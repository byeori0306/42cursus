/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:39:53 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/19 17:11:29 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main(void) {
	Data data1;
	data1.data = "precious data";
	uintptr_t raw = serialize(&data1);
	Data* data2 = deserialize(raw);
	
	std::cout << data1.data << std::endl;
	std::cout << &(data1.data) << std::endl;
	std::cout << data2->data << std::endl;
	std::cout << &(data2->data) << std::endl;
}